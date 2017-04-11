INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../../code/lib ../../code/external/eigen/)

ADD_EXECUTABLE(RunUnitTests
               test_mean_curvature_solver.cpp)

TARGET_LINK_LIBRARIES(RunUnitTests gtest gtest_main)
TARGET_LINK_LIBRARIES(RunUnitTests mean_curvature_lib)