#include <iostream>
#include "gtest/gtest.h"
#include <Eigen/Core>
#include <memory>
#include "mean_curvature_solver.h"
#include "uniform_lb_operator.h"

class MeanCurvatureSolverTest : public ::testing::Test {
protected:
    MeanCurvatureSolverTest() : mUnifromMCS(mcurv::uniformLBOperatorStrategy),
                                mBunnyPath("./res/bunny.off") {
    }

    virtual ~MeanCurvatureSolverTest() {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:
    virtual void SetUp() {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }

    Eigen::MatrixXd mSolution;
    const std::string mBunnyPath;
    mcurv::MeanCurvatureSolver mUnifromMCS;
};

TEST_F(MeanCurvatureSolverTest, WrongPathForExecute) {
    ASSERT_THROW(mUnifromMCS.Execute(mSolution, "wrong_path"), std::runtime_error);
}

TEST_F(MeanCurvatureSolverTest, Exec) {
    mUnifromMCS.Execute(mSolution, mBunnyPath);
}