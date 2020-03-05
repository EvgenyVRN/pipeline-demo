#include "src/Pipeline.h"
#include "src/PlusSolver.h"
#include "src/MinusSolver.h"

#include <gtest/gtest.h>

using namespace std;
//class TestPipline : public ::testing::Test
//{
//public:
//    TestPipline() { /* init protected members here */ }
//    ~TestPipline() { /* free protected members here */ }
//    void SetUp() { /* called before every test */ }
//    void TearDown() { /* called after every test */ }

//protected:
//    /* none yet */
//};

TEST(Pipeline, EmptyPipeline)
{
    Pipeline pipeline;
    vector<double> data = {1, 2, 3, 4, 5};
    auto res = pipeline.Solve(data);
    EXPECT_EQ(data, res);
}

TEST(Pipeline, PlusSolver)
{
    Pipeline pipeline;
    pipeline.AddSolver(make_unique<PlusSolver>());
    vector<double> data = {1, 2, 3, 4, 5};
    auto res = pipeline.Solve(data);

    vector<double> expected = {2, 3, 4, 5, 6};
    EXPECT_EQ(expected, res);
}

TEST(Pipeline, MinusSolver)
{
    Pipeline pipeline;
    pipeline.AddSolver(make_unique<MinusSolver>());
    vector<double> data = {1, 2, 3, 4, 5};
    auto res = pipeline.Solve(data);

    vector<double> expected = {-1, 0, 1, 2, 3};
    EXPECT_EQ(expected, res);
}

TEST(Pipeline, PlusMinusSolver)
{
    Pipeline pipeline;
    pipeline.AddSolver(make_unique<PlusSolver>());
    pipeline.AddSolver(make_unique<MinusSolver>());
    vector<double> data = {1, 2, 3, 4, 5};
    auto res = pipeline.Solve(data);

    vector<double> expected = {0, 1, 2, 3, 4};
    EXPECT_EQ(expected, res);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
