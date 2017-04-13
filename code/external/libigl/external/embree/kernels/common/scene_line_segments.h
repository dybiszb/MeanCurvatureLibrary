// ======================================================================== //
// Copyright 2009-2015 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#pragma once

#include "default.h"
#include "geometry.h"
#include "primref.h"
#include "buffer.h"

namespace embree
{
  /*! represents an array of line segments */
  struct LineSegments : public Geometry
  {
    /*! type of this geometry */
    static const Geometry::Type geom_type = Geometry::LINE_SEGMENTS;

  public:

    /*! line segments construction */
    LineSegments (Scene* parent, RTCGeometryFlags flags, size_t numPrimitives, size_t numVertices, size_t numTimeSteps);

    /*! writes the bezier segment geometry to disk */
    void write(std::ofstream& file);

  public:
    void enabling();
    void disabling();
    void setMask (unsigned mask);
    void setBuffer(RTCBufferType type, void* ptr, size_t offset, size_t stride);
    void* map(RTCBufferType type);
    void unmap(RTCBufferType type);
    void immutable ();
    bool verify ();
    void interpolate(unsigned primID, float u, float v, RTCBufferType buffer, float* P, float* dPdu, float* dPdv, size_t numFloats);
    // FIXME: implement interpolateN

  public:

    /*! returns number of line segments */
    __forceinline size_t size() const {
      return segments.size();
    }

    /*! returns the number of vertices */
    __forceinline size_t numVertices() const {
      return vertices[0].size();
    }

    /*! returns the i'th segment */
    __forceinline const int& segment(size_t i) const {
      return segments[i];
    }

    /*! returns i'th vertex of j'th timestep */
    __forceinline Vec3fa vertex(size_t i, size_t j = 0) const {
      return vertices[j][i];
    }

    /*! returns i'th vertex of j'th timestep */
    __forceinline const char* vertexPtr(size_t i, size_t j = 0) const {
      return vertices[j].getPtr(i);
    }

    /*! returns i'th radius of j'th timestep */
    __forceinline float radius(size_t i, size_t j = 0) const {
      return vertices[j][i].w;
    }

    /*! check if the i'th primitive is valid */
    __forceinline bool valid(size_t i, BBox3fa* bbox = nullptr) const
    {
      const int index = segment(i);
      if (index < 0 || index+1 >= numVertices()) return false;

      for (size_t j=0; j<numTimeSteps; j++)
      {
        const float r0 = radius(index+0,j);
        const float r1 = radius(index+1,j);
        if (!isvalid(r0) || !isvalid(r1))
          return false;
        if (min(r0,r1) < 0.0f)
          return false;

        const Vec3fa v0 = vertex(index+0,j);
        const Vec3fa v1 = vertex(index+1,j);
        if (!isvalid(v0) || !isvalid(v1))
          return false;
      }

      if (bbox) *bbox = bounds(i);
      return true;
    }

    /*! calculates bounding box of i'th line segment */
    __forceinline BBox3fa bounds(size_t i, size_t j = 0) const
    {
      const int index = segment(i);
      const float r0 = radius(index+0,j);
      const float r1 = radius(index+1,j);
      const Vec3fa v0 = vertex(index+0,j);
      const Vec3fa v1 = vertex(index+1,j);
      const BBox3fa b = merge(BBox3fa(v0),BBox3fa(v1));
      return enlarge(b,Vec3fa(max(r0,r1)));
    }

    /*! calculates bounding box of i'th line segment */
    __forceinline BBox3fa bounds(const AffineSpace3fa& space, size_t i, size_t j = 0) const
    {
      const int index = segment(i);
      const float r0 = radius(index+0,j);
      const float r1 = radius(index+1,j);
      const Vec3fa v0 = xfmPoint(space,vertex(index+0,j));
      const Vec3fa v1 = xfmPoint(space,vertex(index+1,j));
      const BBox3fa b = merge(BBox3fa(v0),BBox3fa(v1));
      return enlarge(b,Vec3fa(max(r0,r1)));
    }

#if defined(__MIC__)

    __forceinline const Vec3fa* fristVertexPtr(size_t i) const { // FIXME: remove, use buffer to access vertices instead!
      return (const Vec3fa*) vertices[0].getPtr(segment(i));
    }

    /*! calculates bounding box of i'th bezier segment */
    __forceinline Vec2vf16 bounds_Vec2f16(size_t i) const
    {
      const int index = segment(i);
      const float* cp0 = (float*) vertices[0].getPtr(index+0);
      const float* cp1 = (float*) vertices[0].getPtr(index+1);
      const float* cp2 = (float*) vertices[0].getPtr(index+2);
      const float* cp3 = (float*) vertices[0].getPtr(index+3);

      const vbool16 m_4f = 0xf;
      const vfloat16 v0 = shuffle4<0,0,0,0>(vfloat16::loadu(m_4f,cp0));
      const vfloat16 v1 = shuffle4<0,0,0,0>(vfloat16::loadu(m_4f,cp1));
      const vfloat16 v2 = shuffle4<0,0,0,0>(vfloat16::loadu(m_4f,cp2));
      const vfloat16 v3 = shuffle4<0,0,0,0>(vfloat16::loadu(m_4f,cp3));

      const vfloat16 b_min = min(min(v0,v1),min(v2,v3));
      const vfloat16 b_max = max(max(v0,v1),max(v2,v3));

      const vfloat16 b_min_r = b_min - swDDDD(b_max);
      const vfloat16 b_max_r = b_max + swDDDD(b_max);

      return Vec2vf16(b_min_r,b_max_r);
    }

#endif

  public:
    BufferT<int> segments;                          //!< array of line segment indices
    array_t<BufferT<Vec3fa>,2> vertices;            //!< vertex array
    array_t<std::unique_ptr<Buffer>,2> userbuffers; //!< user buffers
  };
}
