#include "off_model.h"

using namespace mcurv;

OFFModel::OFFModel(const std::string &path) {
    igl::readOFF(path, mVertices, mFaces);
    igl::per_vertex_normals(mVertices, mFaces, mNormals);
}

const VerticesT& OFFModel::GetVertices() {
    return mVertices;
}

const FacesT& OFFModel::GetFaces() {
    return mFaces;
}

const NormalsT& OFFModel::GetNormals() {

}