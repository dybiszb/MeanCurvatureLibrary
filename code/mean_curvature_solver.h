#ifndef MEAN_CURVATURE_SOLVER_H
#define MEAN_CURVATURE_SOLVER_H

#include <memory>
#include <Eigen/Core>
#include "types_definitions.h"
#include "external/libigl/include/igl/readOFF.h"

namespace mcurv {

    class MeanCurvatureSolver {
    public:
        MeanCurvatureSolver(const SolverStrategyT& strategy);
        void Execute(Eigen::MatrixXd &solution, const std::string& path);
    private:
        const SolverStrategyT mStrategy;
        VerticesT mVertices;
    };
}

#endif
