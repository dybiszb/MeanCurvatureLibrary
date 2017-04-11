# Install script for directory: /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen" TYPE FILE FILES
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/StdDeque"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/SparseQR"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/StdList"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/SparseCholesky"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/Core"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/Sparse"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/Jacobi"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/Eigenvalues"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/Eigen"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/QtAlignedMalloc"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/UmfPackSupport"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/Householder"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/IterativeLinearSolvers"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/SPQRSupport"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/SuperLUSupport"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/StdVector"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/SVD"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/Cholesky"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/OrderingMethods"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/SparseLU"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/PaStiXSupport"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/Dense"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/LU"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/PardisoSupport"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/CholmodSupport"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/MetisSupport"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/SparseCore"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/QR"
    "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/Geometry"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen" TYPE DIRECTORY FILES "/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/Eigen/src" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

