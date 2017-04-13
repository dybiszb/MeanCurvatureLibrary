#ifndef TYPES_DEFINITIONS_H
#define TYPES_DEFINITIONS_H

#include <Eigen/Core>
#include <Eigen/Sparse>
#include <functional>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#include <map>
#include <set>

namespace mcurv {

    /**
     * Dynamically sized matrix of points in rows, a "point cloud".
     */
    using VerticesT = Eigen::MatrixXd;

    /**
     * Dynamically sized matrix of vectors in rows, a list of normals.
     */
    using NormalsT = Eigen::MatrixXd;

    /**
     * Dynamically sized matrix of face vertex indices in rows.
     */
    using FacesT = Eigen::MatrixXi;

    /**
     * OpenMesh' mesh structure. Useful in case of one-ring neighbourhood.
     */
    using OMMeshT = OpenMesh::TriMesh_ArrayKernelT<>;

    /**
     * An associative storage of neighbour indices for point cloud
     * { pointId => [neighbourId_0, nId_1, ... nId_k-1] }
     */
    using NeighborhoodT = std::map<int, std::set<size_t>>;

    /**
     * A function that will calculate a specific type of Laplace-Beltrami
     * operator
     */
    using SolverStrategyT = std::function<void(Eigen::MatrixXd& solution,
                                               const VerticesT &vertices,
                                               const NormalsT &normals,
                                               const NeighborhoodT &neighbours,
                                               OMMeshT &omMesh)>;
    /**
     * Eigen's triplet structure for sparse matrix.
     */
    using TripletT = Eigen::Triplet<double>;

    /**
     * Eigen's sparse matrix structure.
     */
    using SparseMatT = Eigen::SparseMatrix<double>;

}

#endif
