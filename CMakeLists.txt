cmake_minimum_required(VERSION 2.6)
project(MeanCurvatureLibrary)

set(CMAKE_CXX_STANDARD 11)

option(test "Build all tests." ON)

ADD_SUBDIRECTORY(code)

if (test)
    ADD_SUBDIRECTORY(testing)
endif()
