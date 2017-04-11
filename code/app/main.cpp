#include <iostream>
#include <Eigen/Core>
#include "../mean_curvature_solver.h"
#include "../uniform_lb_operator.h"

using namespace std;

int main() {
    Eigen::MatrixXd meanCurv;
    mcurv::MeanCurvatureSolver mcs(mcurv::uniformLBOperator);
    mcs.Execute(meanCurv);
}