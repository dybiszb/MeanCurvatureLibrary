#ifndef OFF_MODEL_H
#define OFF_MODEL_H

#include <iostream>
#include "types_definitions.h"
#include "external/libigl/include/igl/readOFF.h"
#include "external/libigl/include/igl/per_vertex_normals.h"

namespace mcurv {

    class OFFModel {
    public:
        OFFModel(const std::string &path);

        const VerticesT &GetVertices();

        const FacesT &GetFaces();

        const NormalsT &GetNormals();

    private:
        VerticesT mVertices;
        FacesT mFaces;
        NormalsT mNormals;
    };

}


#endif
