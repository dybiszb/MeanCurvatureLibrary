#include "mean_curvature_solver.h"

using namespace mcurv;

MeanCurvatureSolver::MeanCurvatureSolver(const SolverStrategyT &strategy)
        : mStrategy(strategy) {
}

void MeanCurvatureSolver::Execute(Eigen::MatrixXd &solution,
                                  const std::string &path) {
    OFFModel model(path);
    mStrategy(solution, model.GetVertices(), model.GetNormals(),
              model.GetNeighborhood(), model.GetOpenMeshModelStructure());
}