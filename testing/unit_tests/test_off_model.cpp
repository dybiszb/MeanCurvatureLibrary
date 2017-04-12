#include "gtest/gtest.h"
#include "off_model.h"
#include "types_definitions.h"

class OffModelTest : public ::testing::Test {
protected:
    OffModelTest() : mBunnyPath("./res/bunny.off"),
                     mModel(mBunnyPath),
                     mNumberOfVertices(3485),
                     mNumberOfFaces(6966) {
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
    mcurv::OFFModel mModel;
    const size_t mNumberOfVertices;
    const size_t mNumberOfFaces;
};

TEST_F(OffModelTest, CheckVertices) {
    const mcurv::VerticesT v = mModel.GetVertices();

    // Check number of loaded vertices
    EXPECT_EQ(mNumberOfVertices, v.rows());

    // Check first loaded vertex
    EXPECT_EQ(-0.0260146, v(0, 0));
    EXPECT_EQ(0.112578, v(0, 1));
    EXPECT_EQ(0.0363871, v(0, 2));

    // Check last loaded vertex
    EXPECT_EQ(-0.0396435, v(mNumberOfVertices - 1, 0));
    EXPECT_EQ(0.152397, v(mNumberOfVertices - 1, 1));
    EXPECT_EQ(-0.00721968, v(mNumberOfVertices - 1, 2));
}

TEST_F(OffModelTest, CheckFaces) {
    const mcurv::FacesT f = mModel.GetFaces();

    // Check number of loaded vertices
    EXPECT_EQ(mNumberOfFaces, f.rows());

    // Check first loaded face
    EXPECT_EQ(2784, f(0, 0));
    EXPECT_EQ(2497, f(0, 1));
    EXPECT_EQ(2027, f(0, 2));

    // Check last loaded face
    EXPECT_EQ(3086, f(mNumberOfFaces - 1, 0));
    EXPECT_EQ(3151, f(mNumberOfFaces - 1, 1));
    EXPECT_EQ(3085, f(mNumberOfFaces - 1, 2));
}

TEST_F(OffModelTest, CheckNormals) {
    const mcurv::NormalsT n = mModel.GetNormals();
//    std::cout << n << std::endl;
    // Check if number of loaded normals equals number of vertices
    EXPECT_EQ(mNumberOfVertices, n.rows());

    // Check first loaded normal
//    EXPECT_EQ(-0.29688 , n(0, 0));
//    EXPECT_EQ(0.630271  , n(0, 1));
//    EXPECT_EQ( 0.717371, n(0, 2));

//    // Check last loaded normal
//    EXPECT_EQ(0.0469531 , n(mNumberOfVertices - 1, 0));
//    EXPECT_EQ(-0.699443, n(mNumberOfVertices - 1, 1));
//    EXPECT_EQ(-0.713144, n(mNumberOfVertices - 1, 2));
}

TEST_F(OffModelTest, CheckNeighborhood) {
    const mcurv::NeighborhoodT ngh = mModel.GetNeighborhood();

    // Must be as many entries as vertices in the model
    EXPECT_EQ(mNumberOfVertices, ngh.size());

    // Check the neighborhood of the first vertex
    long unsigned int firstVertexNgh[] = {3, 24, 308, 525, 542};
    std::set<long unsigned int> assumedNgh(firstVertexNgh, firstVertexNgh + 5);
    const auto &loadedNgh = ngh.begin()->second;
    EXPECT_EQ(assumedNgh, loadedNgh);

}

TEST_F(OffModelTest, WrongPath) {
    ASSERT_THROW(mcurv::OFFModel("wrong_path"), std::runtime_error);
}