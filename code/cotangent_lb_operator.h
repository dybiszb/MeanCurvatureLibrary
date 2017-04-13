#ifndef COTANGENT_LB_OPERATOR_H
#define COTANGENT_LB_OPERATOR_H

#include "types_definitions.h"
#include "utilities.h"

namespace mcurv {

    void cotangentLBOperatorStrategy(Eigen::MatrixXd& solution,
                                   const VerticesT &vertices,
                                   const NormalsT &normals,
                                   const NeighborhoodT &neighbours,
                                   OMMeshT &omMesh);

    /**
     * Calcuates Laplace-Beltrami operator for provided vertices and their
     * one-ring neighbourhoods.
     *
     * @tparam Derived
     * @param coordinates Model's vertices
     * @param omMesh      OpenMesh's mesh structure.
     * @return            Sparse matrix with Laplace-Beltrami operator with
     *                    cotangent discretization.
     */
    template<typename Derived>
    SparseMatT 
    cotangentLBOperator(
            Eigen::MatrixBase<Derived> const &coordinates,
            const OMMeshT &omMesh);
    
}


#endif
