cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(MeanCurvatureLibrary)

set(CMAKE_CXX_STANDARD 11)

option(test "Build all tests." ON)

ADD_SUBDIRECTORY(code)

if (test)
    ADD_SUBDIRECTORY(testing)
endif()
