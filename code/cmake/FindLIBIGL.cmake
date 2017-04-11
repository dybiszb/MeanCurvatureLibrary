# - Try to find the LIBIGL library
# Once done this will define
#
#  LIBIGL_FOUND - system has LIBIGL
#  LIBIGL_INCLUDE_DIR - **the** LIBIGL include directory
#  LIBIGL_INCLUDE_DIRS - LIBIGL include directories
#  LIBIGL_SOURCES - the LIBIGL source files
if(NOT LIBIGL_FOUND)

FIND_PATH(LIBIGL_INCLUDE_DIR igl/readOBJ.h
   ${PROJECT_SOURCE_DIR}/../../include
   ${PROJECT_SOURCE_DIR}/../include
   ${PROJECT_SOURCE_DIR}/include
   ${PROJECT_SOURCE_DIR}/../libigl/include
   ${PROJECT_SOURCE_DIR}/../../libigl/include
   ${PROJECT_SOURCE_DIR}/external/libigl/include
   $ENV{LIBIGL}/include
   $ENV{LIBIGLROOT}/include
   $ENV{LIBIGL_ROOT}/include
   $ENV{LIBIGL_DIR}/include
   $ENV{LIBIGL_DIR}/inc
   /usr/include
   /usr/local/include
   /usr/local/igl/libigl/include
)


if(LIBIGL_INCLUDE_DIR)
   set(LIBIGL_FOUND TRUE)
   set(LIBIGL_INCLUDE_DIRS ${LIBIGL_INCLUDE_DIR}  ${LIBIGL_INCLUDE_DIR}/../external/Singular_Value_Decomposition)
   #set(LIBIGL_SOURCES
   #   ${LIBIGL_INCLUDE_DIR}/igl/viewer/Viewer.cpp
   #)


   # libigl options: choose between header only and compiled static library
   # Header-only is preferred for small projects. For larger projects the static build
   # considerably reduces the compilation times
   option(LIBIGL_USE_STATIC_LIBRARY "Use LibIGL as static library" OFF)

   # add a customizable menu bar
   option(LIBIGL_WITH_NANOGUI     "Use Nanogui menu"   ON)

   # libigl options: choose your dependencies (by default everything is OFF except opengl)
   option(LIBIGL_WITH_VIEWER      "Use OpenGL viewer"  ON)
   option(LIBIGL_WITH_OPENGL      "Use OpenGL"         ON)
   option(LIBIGL_WITH_OPENGL_GLFW "Use GLFW"           ON)
   option(LIBIGL_WITH_BBW         "Use BBW"            OFF)
   option(LIBIGL_WITH_EMBREE      "Use Embree"         OFF)
   option(LIBIGL_WITH_PNG         "Use PNG"            OFF)
   option(LIBIGL_WITH_TETGEN      "Use Tetgen"         OFF)
   option(LIBIGL_WITH_TRIANGLE    "Use Triangle"       OFF)
   option(LIBIGL_WITH_XML         "Use XML"            OFF)
   option(LIBIGL_WITH_LIM         "Use LIM"            OFF)
   option(LIBIGL_WITH_COMISO      "Use CoMiso"         OFF)
   option(LIBIGL_WITH_MATLAB      "Use Matlab"         OFF) # This option is not supported yet
   option(LIBIGL_WITH_MOSEK       "Use MOSEK"          OFF) # This option is not supported yet
   option(LIBIGL_WITH_CGAL        "Use CGAL"           OFF)
   if(LIBIGL_WITH_CGAL) # Do not remove or move this block, the cgal build system fails without it
      find_package(CGAL REQUIRED)
      set(CGAL_DONT_OVERRIDE_CMAKE_FLAGS TRUE CACHE BOOL "CGAL's CMAKE Setup is super annoying ")
      include(${CGAL_USE_FILE})
   endif()


   # libigl information
   message("libigl includes: ${LIBIGL_INCLUDE_DIRS}")
   message("libigl libraries: ${LIBIGL_LIBRARIES}")
   message("libigl extra sources: ${LIBIGL_EXTRA_SOURCES}")
   message("libigl extra libraries: ${LIBIGL_EXTRA_LIBRARIES}")
   message("libigl definitions: ${LIBIGL_DEFINITIONS}")

endif()

endif()
