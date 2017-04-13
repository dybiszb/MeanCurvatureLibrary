#ifndef MEAN_CURVATURE_SOLVER_H
#define MEAN_CURVATURE_SOLVER_H

#include <memory>
#include <Eigen/Core>
#include "off_model.h"
#include "types_definitions.h"

namespace mcurv {

    class MeanCurvatureSolver {
    public:
        /**
         * Provides means for calculating mean curvature using specified
         * strategy.
         *
         * @param strategy Please reffer to a SolverStrategyT functor located in
         *                 "types_definitions.h. Provided strategy must
         *                 follow its declaration.
         */
        MeanCurvatureSolver(const SolverStrategyT &strategy);

        /**
         * Calculate mean curvature of a model localized on provided path.
         * In order to reduce the overhead of copying, the results matrix
         * is passed by reference.
         *
         * @param solution A matrix of results. It will be filled in by the
         *                 procedure.
         * @param path     Path to .off file.
         */
        void Execute(Eigen::MatrixXd &solution, const std::string &path);

    private:
        const SolverStrategyT mStrategy;
    };
}

#endif
