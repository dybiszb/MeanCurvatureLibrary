#ifndef TYPES_DEFINITIONS_H
#define TYPES_DEFINITIONS_H

#include <Eigen/Core>
#include <functional>

namespace mcurv {
    using SolverStrategyT = std::function<void(Eigen::MatrixXd)>;
}

#endif
