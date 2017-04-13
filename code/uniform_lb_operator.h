#ifndef UNIFORM_LB_OPERATOR_H
#define UNIFORM_LB_OPERATOR_H

#include <iostream>
#include "types_definitions.h"
#include "utilities.h"

namespace mcurv {

    void uniformLBOperatorStrategy(Eigen::MatrixXd& solution,
                                   const VerticesT &vertices,
                                   const NormalsT &normals,
                                   const NeighborhoodT &neighbours,
                                   OMMeshT &omMesh);

    /**
     * Calcuates Laplace-Beltrami operator for provided vertices and their
     * neighbourhoods.
     *
     * @tparam Derived
     * @param coordinates Model's vertices.
     * @param neighbours  Model's neighbourhood. Not 'const' since [] operator
     *                    of the map is not 'const'.
     * @return            Sparse matrix with Laplace-Beltrami operator with
     *                    uniform discretization.
     */
    template<typename Derived>
    SparseMatT
    uniformLBOperator(Eigen::MatrixBase<Derived> const &coordinates,
                      NeighborhoodT &neighbours);

}

#endif
