# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/build

# Utility rule file for product_syrk.

# Include the progress variables for this target.
include test/CMakeFiles/product_syrk.dir/progress.make

product_syrk: test/CMakeFiles/product_syrk.dir/build.make

.PHONY : product_syrk

# Rule to build all files generated by this target.
test/CMakeFiles/product_syrk.dir/build: product_syrk

.PHONY : test/CMakeFiles/product_syrk.dir/build

test/CMakeFiles/product_syrk.dir/clean:
	cd /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/build/test && $(CMAKE_COMMAND) -P CMakeFiles/product_syrk.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/product_syrk.dir/clean

test/CMakeFiles/product_syrk.dir/depend:
	cd /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255 /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/test /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/build /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/build/test /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/build/test/CMakeFiles/product_syrk.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/product_syrk.dir/depend

