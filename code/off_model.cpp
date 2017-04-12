#include "off_model.h"

using namespace mcurv;

OFFModel::OFFModel(const std::string &path) {
    // Load model into IGL framework
    if(!igl::readOFF(path, mVertices, mFaces)) {
        throw std::runtime_error( "Error: Cannot read mesh from " + path);
    }
    igl::per_vertex_normals(mVertices, mFaces, mNormals);

    // Load model into OpenMesh framework
    mOMMesh.request_vertex_normals();
    if (!OpenMesh::IO::read_mesh(mOMMesh, path)) {
        throw std::runtime_error( "Error: Cannot read mesh from " + path);
    }

    calculateNeighbourhood(mFaces, mNeighborhood);
}

// -----------------------------------------------------------------------------
const VerticesT& OFFModel::GetVertices() {
    return mVertices;
}

// -----------------------------------------------------------------------------
const FacesT& OFFModel::GetFaces() {
    return mFaces;
}

// -----------------------------------------------------------------------------
const NormalsT& OFFModel::GetNormals() {
    return mNormals;
}

// -----------------------------------------------------------------------------
const NeighborhoodT  &OFFModel::GetNeighborhood() {
    return mNeighborhood;
}

// -----------------------------------------------------------------------------
OMMeshT& OFFModel::GetOpenMeshModelStructure() {
    return mOMMesh;
}

// -----------------------------------------------------------------------------
void OFFModel::calculateNeighbourhood(const FacesT &faces,
                                        NeighborhoodT &neighbours) {
    const long numberOfNeighbours = faces.rows();
    for (int i = 0; i < numberOfNeighbours; ++i) {
        const size_t i1 = static_cast<const size_t>(faces(i, 0));
        const size_t i2 = static_cast<const size_t>(faces(i, 1));
        const size_t i3 = static_cast<const size_t>(faces(i, 2));

        neighbours[i1].insert(i2);
        neighbours[i1].insert(i3);
        neighbours[i2].insert(i1);
        neighbours[i2].insert(i3);
        neighbours[i3].insert(i1);
        neighbours[i3].insert(i2);
    }
}