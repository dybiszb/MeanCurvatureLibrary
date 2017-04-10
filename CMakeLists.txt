cmake_minimum_required(VERSION 3.6)
project(MeanCurvatureLibrary)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(MeanCurvatureApp ${SOURCE_FILES})

INCLUDE_DIRECTORIES(code)
ADD_SUBDIRECTORY(code)
ADD_SUBDIRECTORY(testing)

TARGET_LINK_LIBRARIES(MeanCurvatureApp mean_curvature_lib)