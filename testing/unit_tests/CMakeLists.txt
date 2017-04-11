INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../../code ../../code/external/eigen/)

ADD_EXECUTABLE(RunUnitTests
               test_mean_curvature_solver.cpp
        test_off_model.cpp)

TARGET_LINK_LIBRARIES(RunUnitTests gtest gtest_main)
TARGET_LINK_LIBRARIES(RunUnitTests mean_curvature_lib)

#===============================================================================
# Copy Resources
#-------------------------------------------------------------------------------
ADD_CUSTOM_COMMAND(
        TARGET RunUnitTests PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory   # Copy resources
        ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:RunUnitTests>/res
)