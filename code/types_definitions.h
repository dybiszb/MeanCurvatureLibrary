#ifndef TYPES_DEFINITIONS_H
#define TYPES_DEFINITIONS_H

#include <Eigen/Core>
#include <functional>

namespace mcurv {
    using SolverStrategyT = std::function<void(Eigen::MatrixXd)>;

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

}

#endif
