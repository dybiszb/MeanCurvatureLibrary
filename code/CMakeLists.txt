project(mean_curvature_lib)

#===============================================================================
# Find LibGL
#-------------------------------------------------------------------------------
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(LIBIGL REQUIRED)

if (NOT LIBIGL_FOUND)
    message(FATAL_ERROR "libigl not found --- You can download it using: \n git clone --recursive https://github.com/libigl/libigl.git ${PROJECT_SOURCE_DIR}/../libigl")
endif ()


#===============================================================================
# Find OpenMesh
#-------------------------------------------------------------------------------
FIND_PACKAGE(OpenMesh REQUIRED)
if (OPENMESH_FOUND)
    MESSAGE("OpenMesh Found!")
    INCLUDE_DIRECTORIES(OPENMESH_INCLUDE_DIR)
else (OPENMESH_FOUND)
    MESSAGE(FATAL_ERROR "OpenMesh NOT Found")
endif (OPENMESH_FOUND)

# Adding libigl: choose the path to your local copy libigl
# This is going to compile everything you requested
add_subdirectory("${LIBIGL_INCLUDE_DIR}/../shared/cmake" "libigl")

# Prepare the build environment
include_directories(${LIBIGL_INCLUDE_DIRS} external/eigen external/)
add_definitions(${LIBIGL_DEFINITIONS})

#FILE(GLOB LIB_SOURCE_FILES *.cpp)
SET(LIB_SOURCE_FILES off_model.cpp cotangent_lb_operator.cpp uniform_lb_operator.cpp mean_curvature_solver.cpp)
add_library(mean_curvature_lib ${LIB_SOURCE_FILES} ${LIBIGL_EXTRA_SOURCES})
target_link_libraries(mean_curvature_lib ${LIBIGL_LIBRARIES} ${LIBIGL_EXTRA_LIBRARIES} ${OPENMESH_LIBRARIES})

add_executable(MeanCurvatureApp app/main.cpp)
TARGET_LINK_LIBRARIES(MeanCurvatureApp mean_curvature_lib)
