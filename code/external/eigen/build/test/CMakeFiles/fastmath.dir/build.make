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

# Include any dependencies generated for this target.
include test/CMakeFiles/fastmath.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/fastmath.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/fastmath.dir/flags.make

test/CMakeFiles/fastmath.dir/fastmath.cpp.o: test/CMakeFiles/fastmath.dir/flags.make
test/CMakeFiles/fastmath.dir/fastmath.cpp.o: ../test/fastmath.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/fastmath.dir/fastmath.cpp.o"
	cd /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/build/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fastmath.dir/fastmath.cpp.o -c /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/test/fastmath.cpp

test/CMakeFiles/fastmath.dir/fastmath.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fastmath.dir/fastmath.cpp.i"
	cd /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/test/fastmath.cpp > CMakeFiles/fastmath.dir/fastmath.cpp.i

test/CMakeFiles/fastmath.dir/fastmath.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fastmath.dir/fastmath.cpp.s"
	cd /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/test/fastmath.cpp -o CMakeFiles/fastmath.dir/fastmath.cpp.s

test/CMakeFiles/fastmath.dir/fastmath.cpp.o.requires:

.PHONY : test/CMakeFiles/fastmath.dir/fastmath.cpp.o.requires

test/CMakeFiles/fastmath.dir/fastmath.cpp.o.provides: test/CMakeFiles/fastmath.dir/fastmath.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/fastmath.dir/build.make test/CMakeFiles/fastmath.dir/fastmath.cpp.o.provides.build
.PHONY : test/CMakeFiles/fastmath.dir/fastmath.cpp.o.provides

test/CMakeFiles/fastmath.dir/fastmath.cpp.o.provides.build: test/CMakeFiles/fastmath.dir/fastmath.cpp.o


# Object files for target fastmath
fastmath_OBJECTS = \
"CMakeFiles/fastmath.dir/fastmath.cpp.o"

# External object files for target fastmath
fastmath_EXTERNAL_OBJECTS =

test/fastmath: test/CMakeFiles/fastmath.dir/fastmath.cpp.o
test/fastmath: test/CMakeFiles/fastmath.dir/build.make
test/fastmath: test/CMakeFiles/fastmath.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fastmath"
	cd /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fastmath.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/fastmath.dir/build: test/fastmath

.PHONY : test/CMakeFiles/fastmath.dir/build

test/CMakeFiles/fastmath.dir/requires: test/CMakeFiles/fastmath.dir/fastmath.cpp.o.requires

.PHONY : test/CMakeFiles/fastmath.dir/requires

test/CMakeFiles/fastmath.dir/clean:
	cd /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/build/test && $(CMAKE_COMMAND) -P CMakeFiles/fastmath.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/fastmath.dir/clean

test/CMakeFiles/fastmath.dir/depend:
	cd /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255 /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/test /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/build /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/build/test /home/dybisz/Downloads/eigen/eigen-eigen-da9b4e14c255/build/test/CMakeFiles/fastmath.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/fastmath.dir/depend

