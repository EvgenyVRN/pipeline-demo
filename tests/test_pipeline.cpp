#include <gtest/gtest.h>


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

TEST(Pipeline, Test1)
{
    EXPECT_EQ(1,1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
