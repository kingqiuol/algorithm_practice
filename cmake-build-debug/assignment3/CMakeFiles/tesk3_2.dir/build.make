# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /cygdrive/c/Users/jinqiu/.CLion2016.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/jinqiu/.CLion2016.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug

# Include any dependencies generated for this target.
include assignment3/CMakeFiles/tesk3_2.dir/depend.make

# Include the progress variables for this target.
include assignment3/CMakeFiles/tesk3_2.dir/progress.make

# Include the compile flags for this target's objects.
include assignment3/CMakeFiles/tesk3_2.dir/flags.make

assignment3/CMakeFiles/tesk3_2.dir/binary_chop.cpp.o: assignment3/CMakeFiles/tesk3_2.dir/flags.make
assignment3/CMakeFiles/tesk3_2.dir/binary_chop.cpp.o: ../assignment3/binary_chop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object assignment3/CMakeFiles/tesk3_2.dir/binary_chop.cpp.o"
	cd /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/assignment3 && /usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tesk3_2.dir/binary_chop.cpp.o -c /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/assignment3/binary_chop.cpp

assignment3/CMakeFiles/tesk3_2.dir/binary_chop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tesk3_2.dir/binary_chop.cpp.i"
	cd /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/assignment3 && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/assignment3/binary_chop.cpp > CMakeFiles/tesk3_2.dir/binary_chop.cpp.i

assignment3/CMakeFiles/tesk3_2.dir/binary_chop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tesk3_2.dir/binary_chop.cpp.s"
	cd /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/assignment3 && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/assignment3/binary_chop.cpp -o CMakeFiles/tesk3_2.dir/binary_chop.cpp.s

assignment3/CMakeFiles/tesk3_2.dir/binary_chop.cpp.o.requires:

.PHONY : assignment3/CMakeFiles/tesk3_2.dir/binary_chop.cpp.o.requires

assignment3/CMakeFiles/tesk3_2.dir/binary_chop.cpp.o.provides: assignment3/CMakeFiles/tesk3_2.dir/binary_chop.cpp.o.requires
	$(MAKE) -f assignment3/CMakeFiles/tesk3_2.dir/build.make assignment3/CMakeFiles/tesk3_2.dir/binary_chop.cpp.o.provides.build
.PHONY : assignment3/CMakeFiles/tesk3_2.dir/binary_chop.cpp.o.provides

assignment3/CMakeFiles/tesk3_2.dir/binary_chop.cpp.o.provides.build: assignment3/CMakeFiles/tesk3_2.dir/binary_chop.cpp.o


# Object files for target tesk3_2
tesk3_2_OBJECTS = \
"CMakeFiles/tesk3_2.dir/binary_chop.cpp.o"

# External object files for target tesk3_2
tesk3_2_EXTERNAL_OBJECTS =

assignment3/tesk3_2.exe: assignment3/CMakeFiles/tesk3_2.dir/binary_chop.cpp.o
assignment3/tesk3_2.exe: assignment3/CMakeFiles/tesk3_2.dir/build.make
assignment3/tesk3_2.exe: assignment3/CMakeFiles/tesk3_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tesk3_2.exe"
	cd /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/assignment3 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tesk3_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
assignment3/CMakeFiles/tesk3_2.dir/build: assignment3/tesk3_2.exe

.PHONY : assignment3/CMakeFiles/tesk3_2.dir/build

assignment3/CMakeFiles/tesk3_2.dir/requires: assignment3/CMakeFiles/tesk3_2.dir/binary_chop.cpp.o.requires

.PHONY : assignment3/CMakeFiles/tesk3_2.dir/requires

assignment3/CMakeFiles/tesk3_2.dir/clean:
	cd /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/assignment3 && $(CMAKE_COMMAND) -P CMakeFiles/tesk3_2.dir/cmake_clean.cmake
.PHONY : assignment3/CMakeFiles/tesk3_2.dir/clean

assignment3/CMakeFiles/tesk3_2.dir/depend:
	cd /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/assignment3 /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/assignment3 /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/assignment3/CMakeFiles/tesk3_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : assignment3/CMakeFiles/tesk3_2.dir/depend

