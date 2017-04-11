#include "gtest/gtest.h"
#include "off_model.h"

class OffModelTest : public ::testing::Test {
protected:
    OffModelTest() : mBunnyPath("./res/bunny.off") {
    }

    virtual ~OffModelTest() {
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

    const std::string mBunnyPath;
};

TEST_F(OffModelTest, OffModelCheckNormals) {


}