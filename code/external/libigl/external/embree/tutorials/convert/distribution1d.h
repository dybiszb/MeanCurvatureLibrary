// ======================================================================== //
// Copyright 2009-2011 Intel Corporation                                    //
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

#ifndef __VOXEL_DISTRIBUTION_1D_H__
#define __VOXEL_DISTRIBUTION_1D_H__

#include "default.h"

namespace embree
{
  /*! 1D probability distribution. The probability distribution
   *  function (PDF) can be initialized with arbitrary data and be
   *  sampled. */
  class Distribution1D : public RefCount
  {
  public:

    /*! Default construction. */
    Distribution1D();

    /*! Construction from distribution array f. */
    Distribution1D(const float* f, const size_t size);

    /*! Destruction. */
    ~Distribution1D();

    /*! Initialized the PDF and CDF arrays. */
    void init(const float* f, const size_t size);

  public:

    /*! Draws a sample from the distribution. \param u is a random
     *  number to use for sampling */
    float sample(const float u) const;

    /*! Returns the probability density a sample would be drawn from location p. */
    float pdf(const float p) const;

  private:
    size_t size;  //!< Number of elements in the PDF
    float* PDF;   //!< Probability distribution function
    float* CDF;   //!< Cumulative distribution function (required for sampling)
  };
}

#endif
