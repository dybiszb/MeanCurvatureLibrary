#ifndef OFF_MODEL_H
#define OFF_MODEL_H

#include <OpenMesh/Core/IO/MeshIO.hh>
#include <iostream>
#include "types_definitions.h"
#include "external/libigl/include/igl/readOFF.h"
#include "external/libigl/include/igl/per_vertex_normals.h"


namespace mcurv {

    class OFFModel {
    public:
        /**
         * Prepare all relevant structures based on model from provided path
         *
         * @param path Path to a model of format .off. If the format is different
         *             or path is not correct the std::runtime_error will be thrown.
         */
        OFFModel(const std::string &path);

        /**
         * Retrieve vertices of the model.
         *
         * @return nx3 matrix of vertices, where n is number of vertices.
         */
        const VerticesT &GetVertices();

        /**
         * Retrieve faces of the model.
         *
         * @return mx3 matrix of faces, where m is number of faces.
         */
        const FacesT &GetFaces();

        /**
         * Retrieve normals of the model. If the model does not come with
         * precalculated normals IGL library will be used to approximate them.
         *
         * @return nx3 matrix of normals, where n is number of normals. Each row
         *         corresponds to a particular vertex.
         */
        const NormalsT &GetNormals();

        /**
         * Retrieve per-vertex neighborhood structure.
         *
         * @return  Please reffer to description of NeighborhoodT type in
         *          types_definitions.h file.
         */
        const NeighborhoodT  &GetNeighborhood();

        /**
         * Retrieve OpenMesh structure of loaded model.
         *
         * @return  Please reffer to description of OMMeshT type in
         *          types_definitions.h file.
         */
        OMMeshT& GetOpenMeshModelStructure();

    private:
        VerticesT mVertices;
        FacesT mFaces;
        NormalsT mNormals;
        OMMeshT mOMMesh;
        NeighborhoodT mNeighborhood;

        /**
         *
         * @param faces      Faces of the model.
         * @param neighbours Neighborhood structure to be filled. In order to
         *                   minimise the overhead of copying, the structure is
         *                   passed by reference.
         */
        void calculateNeighbourhood(const FacesT &faces,
                                    NeighborhoodT &neighbours);
    };

}


#endif
