#include "gtest/gtest.h"
#include "utilities.h"

class UtilitiesTestSuite : public ::testing::Test {
protected:
    UtilitiesTestSuite() : mFilePath("./dumpMatrixTest.txt") { }

    virtual ~UtilitiesTestSuite() {
        try {
            remove(mFilePath.c_str());
        } catch(...) { };
    }

    const std::string mFilePath;
};

TEST_F(UtilitiesTestSuite, MultiplayerFunctior) {
    EXPECT_EQ(mcurv::calculateMultiplier(-20), -1);
    EXPECT_EQ(mcurv::calculateMultiplier(0), 1);
    EXPECT_EQ(mcurv::calculateMultiplier(200.2), 1);
}

TEST_F(UtilitiesTestSuite, DumpToFile_Execution){
    Eigen::MatrixXd m(2, 2);
    m << 1, 2, 3, 4;
    ASSERT_NO_THROW(mcurv::dumpMatrixXdToFile(m, mFilePath));
}

TEST_F(UtilitiesTestSuite, DumpToFile_FileExists) {
    Eigen::MatrixXd m(2, 2);
    m << 1, 2, 3, 4;
    mcurv::dumpMatrixXdToFile(m, mFilePath);

    // Check whether file exists
    std::ifstream f(mFilePath.c_str());
    ASSERT_TRUE(f.good());

}


TEST_F(UtilitiesTestSuite, DumpToFile_SavedCorrectly) {
    Eigen::MatrixXd m(2, 2);
    m << 1, 2, 3, 4;
    mcurv::dumpMatrixXdToFile(m, mFilePath);

    std::ifstream file(mFilePath);
    std::string str;
    ASSERT_TRUE(std::getline(file, str));
    ASSERT_EQ(str, "1 2");
    ASSERT_TRUE(std::getline(file, str));
    ASSERT_EQ(str, "3 4");
}


TEST_F(UtilitiesTestSuite, DumpToFile_WrongPath) {
    Eigen::MatrixXd m(2, 2);
    m << 1, 2, 3, 4;
    ASSERT_ANY_THROW(mcurv::dumpMatrixXdToFile(m, ""));
}