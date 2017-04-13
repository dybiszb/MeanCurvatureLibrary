#include <iostream>
#include "gtest/gtest.h"
#include <Eigen/Core>
#include "mean_curvature_solver.h"
#include "uniform_lb_operator.h"
#include "cotangent_lb_operator.h"

class MeanCurvatureSolverTest : public ::testing::Test {
protected:
    MeanCurvatureSolverTest() : mUnifromMCS(mcurv::uniformLBOperatorStrategy),
                                mCotangentMCS(mcurv::cotangentLBOperatorStrategy),
                                mBunnyPath("./res/bunny.off") {}

    Eigen::MatrixXd mSolution;
    const std::string mBunnyPath;
    mcurv::MeanCurvatureSolver mUnifromMCS;
    mcurv::MeanCurvatureSolver mCotangentMCS;
};

TEST_F(MeanCurvatureSolverTest, WrongPathForExecute) {
    ASSERT_THROW(mUnifromMCS.Execute(mSolution, "wrong_path"), std::runtime_error);
    ASSERT_THROW(mCotangentMCS.Execute(mSolution, "wrong_path"), std::runtime_error);
}

TEST_F(MeanCurvatureSolverTest, Exec) {
    mUnifromMCS.Execute(mSolution, mBunnyPath);
    mCotangentMCS.Execute(mSolution, mBunnyPath);
}