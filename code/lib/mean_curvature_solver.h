#ifndef MEAN_CURVATURE_SOLVER_H
#define MEAN_CURVATURE_SOLVER_H

#include <memory>
#include <Eigen/Core>
#include "types_definitions.h"

namespace mcurv {

    class MeanCurvatureSolver {
    public:
        MeanCurvatureSolver(const SolverStrategyT& strategy);
        void Execute(Eigen::MatrixXd &solution);
    private:
        const SolverStrategyT mStrategy;
    };
}

#endif
