enable_testing()

find_package(GTest CONFIG REQUIRED)

add_executable(tst_pipeline test_pipeline.cpp)
target_link_libraries(tst_pipeline PRIVATE pipeline-lib)
target_link_libraries(tst_pipeline PRIVATE glog::glog)
target_link_libraries(tst_pipeline PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(TestPipline test_pipeline)
