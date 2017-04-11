#include <iostream>
#include "gtest/gtest.h"
#include <Eigen/Core>
#include <memory>
#include "uniform_lb_operator.h"
#include "mean_curvature_solver.h"

class MeanCurvatureSolverTest : public ::testing::Test {
protected:
    MeanCurvatureSolverTest() : mUnifromMCS(
            new mcurv::MeanCurvatureSolver(mcurv::uniformLBOperator)),
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
    std::unique_ptr<mcurv::MeanCurvatureSolver> mUnifromMCS;
};

TEST_F(MeanCurvatureSolverTest, MethodBarDoesAbc) {
    int i = 1;
    EXPECT_EQ(1, i);

    mUnifromMCS->Execute(mSolution, mBunnyPath);

}
