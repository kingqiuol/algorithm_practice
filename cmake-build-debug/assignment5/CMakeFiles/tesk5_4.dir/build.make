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
include assignment5/CMakeFiles/tesk5_4.dir/depend.make

# Include the progress variables for this target.
include assignment5/CMakeFiles/tesk5_4.dir/progress.make

# Include the compile flags for this target's objects.
include assignment5/CMakeFiles/tesk5_4.dir/flags.make

assignment5/CMakeFiles/tesk5_4.dir/search_tree.cpp.o: assignment5/CMakeFiles/tesk5_4.dir/flags.make
assignment5/CMakeFiles/tesk5_4.dir/search_tree.cpp.o: ../assignment5/search_tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object assignment5/CMakeFiles/tesk5_4.dir/search_tree.cpp.o"
	cd /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/assignment5 && /usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tesk5_4.dir/search_tree.cpp.o -c /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/assignment5/search_tree.cpp

assignment5/CMakeFiles/tesk5_4.dir/search_tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tesk5_4.dir/search_tree.cpp.i"
	cd /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/assignment5 && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/assignment5/search_tree.cpp > CMakeFiles/tesk5_4.dir/search_tree.cpp.i

assignment5/CMakeFiles/tesk5_4.dir/search_tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tesk5_4.dir/search_tree.cpp.s"
	cd /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/assignment5 && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/assignment5/search_tree.cpp -o CMakeFiles/tesk5_4.dir/search_tree.cpp.s

assignment5/CMakeFiles/tesk5_4.dir/search_tree.cpp.o.requires:

.PHONY : assignment5/CMakeFiles/tesk5_4.dir/search_tree.cpp.o.requires

assignment5/CMakeFiles/tesk5_4.dir/search_tree.cpp.o.provides: assignment5/CMakeFiles/tesk5_4.dir/search_tree.cpp.o.requires
	$(MAKE) -f assignment5/CMakeFiles/tesk5_4.dir/build.make assignment5/CMakeFiles/tesk5_4.dir/search_tree.cpp.o.provides.build
.PHONY : assignment5/CMakeFiles/tesk5_4.dir/search_tree.cpp.o.provides

assignment5/CMakeFiles/tesk5_4.dir/search_tree.cpp.o.provides.build: assignment5/CMakeFiles/tesk5_4.dir/search_tree.cpp.o


# Object files for target tesk5_4
tesk5_4_OBJECTS = \
"CMakeFiles/tesk5_4.dir/search_tree.cpp.o"

# External object files for target tesk5_4
tesk5_4_EXTERNAL_OBJECTS =

assignment5/tesk5_4.exe: assignment5/CMakeFiles/tesk5_4.dir/search_tree.cpp.o
assignment5/tesk5_4.exe: assignment5/CMakeFiles/tesk5_4.dir/build.make
assignment5/tesk5_4.exe: assignment5/CMakeFiles/tesk5_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tesk5_4.exe"
	cd /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/assignment5 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tesk5_4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
assignment5/CMakeFiles/tesk5_4.dir/build: assignment5/tesk5_4.exe

.PHONY : assignment5/CMakeFiles/tesk5_4.dir/build

assignment5/CMakeFiles/tesk5_4.dir/requires: assignment5/CMakeFiles/tesk5_4.dir/search_tree.cpp.o.requires

.PHONY : assignment5/CMakeFiles/tesk5_4.dir/requires

assignment5/CMakeFiles/tesk5_4.dir/clean:
	cd /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/assignment5 && $(CMAKE_COMMAND) -P CMakeFiles/tesk5_4.dir/cmake_clean.cmake
.PHONY : assignment5/CMakeFiles/tesk5_4.dir/clean

assignment5/CMakeFiles/tesk5_4.dir/depend:
	cd /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/assignment5 /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/assignment5 /cygdrive/e/360MoveData/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/assignment5/CMakeFiles/tesk5_4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : assignment5/CMakeFiles/tesk5_4.dir/depend

