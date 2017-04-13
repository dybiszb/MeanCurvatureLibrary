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

TEST_F(MeanCurvatureSolverTest, ExecUniform) {
    mUnifromMCS.Execute(mSolution, mBunnyPath);

    EXPECT_NEAR(mSolution(0,0), 0.0065769, 0.001);
    EXPECT_NEAR(mSolution(1,0), -0.00329001, 0.001);
    EXPECT_NEAR(mSolution(2,0), -0.00750467, 0.001);
}

TEST_F(MeanCurvatureSolverTest, ExecCotangent) {
    mCotangentMCS.Execute(mSolution, mBunnyPath);

    EXPECT_NEAR(mSolution(0,0), 66.2739, 0.001);
    EXPECT_NEAR(mSolution(1,0), -555.572, 0.001);
    EXPECT_NEAR(mSolution(2,0), -76.9057, 0.001);
}