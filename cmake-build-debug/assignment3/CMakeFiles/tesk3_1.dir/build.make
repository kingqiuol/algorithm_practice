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
CMAKE_SOURCE_DIR = /cygdrive/c/Users/jinqiu/Desktop/tesk

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/jinqiu/Desktop/tesk/cmake-build-debug

# Include any dependencies generated for this target.
include assignment3/CMakeFiles/tesk3_1.dir/depend.make

# Include the progress variables for this target.
include assignment3/CMakeFiles/tesk3_1.dir/progress.make

# Include the compile flags for this target's objects.
include assignment3/CMakeFiles/tesk3_1.dir/flags.make

assignment3/CMakeFiles/tesk3_1.dir/sort.cpp.o: assignment3/CMakeFiles/tesk3_1.dir/flags.make
assignment3/CMakeFiles/tesk3_1.dir/sort.cpp.o: ../assignment3/sort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/jinqiu/Desktop/tesk/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object assignment3/CMakeFiles/tesk3_1.dir/sort.cpp.o"
	cd /cygdrive/c/Users/jinqiu/Desktop/tesk/cmake-build-debug/assignment3 && /usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tesk3_1.dir/sort.cpp.o -c /cygdrive/c/Users/jinqiu/Desktop/tesk/assignment3/sort.cpp

assignment3/CMakeFiles/tesk3_1.dir/sort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tesk3_1.dir/sort.cpp.i"
	cd /cygdrive/c/Users/jinqiu/Desktop/tesk/cmake-build-debug/assignment3 && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/jinqiu/Desktop/tesk/assignment3/sort.cpp > CMakeFiles/tesk3_1.dir/sort.cpp.i

assignment3/CMakeFiles/tesk3_1.dir/sort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tesk3_1.dir/sort.cpp.s"
	cd /cygdrive/c/Users/jinqiu/Desktop/tesk/cmake-build-debug/assignment3 && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/jinqiu/Desktop/tesk/assignment3/sort.cpp -o CMakeFiles/tesk3_1.dir/sort.cpp.s

assignment3/CMakeFiles/tesk3_1.dir/sort.cpp.o.requires:

.PHONY : assignment3/CMakeFiles/tesk3_1.dir/sort.cpp.o.requires

assignment3/CMakeFiles/tesk3_1.dir/sort.cpp.o.provides: assignment3/CMakeFiles/tesk3_1.dir/sort.cpp.o.requires
	$(MAKE) -f assignment3/CMakeFiles/tesk3_1.dir/build.make assignment3/CMakeFiles/tesk3_1.dir/sort.cpp.o.provides.build
.PHONY : assignment3/CMakeFiles/tesk3_1.dir/sort.cpp.o.provides

assignment3/CMakeFiles/tesk3_1.dir/sort.cpp.o.provides.build: assignment3/CMakeFiles/tesk3_1.dir/sort.cpp.o


# Object files for target tesk3_1
tesk3_1_OBJECTS = \
"CMakeFiles/tesk3_1.dir/sort.cpp.o"

# External object files for target tesk3_1
tesk3_1_EXTERNAL_OBJECTS =

assignment3/tesk3_1.exe: assignment3/CMakeFiles/tesk3_1.dir/sort.cpp.o
assignment3/tesk3_1.exe: assignment3/CMakeFiles/tesk3_1.dir/build.make
assignment3/tesk3_1.exe: assignment3/CMakeFiles/tesk3_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/jinqiu/Desktop/tesk/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tesk3_1.exe"
	cd /cygdrive/c/Users/jinqiu/Desktop/tesk/cmake-build-debug/assignment3 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tesk3_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
assignment3/CMakeFiles/tesk3_1.dir/build: assignment3/tesk3_1.exe

.PHONY : assignment3/CMakeFiles/tesk3_1.dir/build

assignment3/CMakeFiles/tesk3_1.dir/requires: assignment3/CMakeFiles/tesk3_1.dir/sort.cpp.o.requires

.PHONY : assignment3/CMakeFiles/tesk3_1.dir/requires

assignment3/CMakeFiles/tesk3_1.dir/clean:
	cd /cygdrive/c/Users/jinqiu/Desktop/tesk/cmake-build-debug/assignment3 && $(CMAKE_COMMAND) -P CMakeFiles/tesk3_1.dir/cmake_clean.cmake
.PHONY : assignment3/CMakeFiles/tesk3_1.dir/clean

assignment3/CMakeFiles/tesk3_1.dir/depend:
	cd /cygdrive/c/Users/jinqiu/Desktop/tesk/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/jinqiu/Desktop/tesk /cygdrive/c/Users/jinqiu/Desktop/tesk/assignment3 /cygdrive/c/Users/jinqiu/Desktop/tesk/cmake-build-debug /cygdrive/c/Users/jinqiu/Desktop/tesk/cmake-build-debug/assignment3 /cygdrive/c/Users/jinqiu/Desktop/tesk/cmake-build-debug/assignment3/CMakeFiles/tesk3_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : assignment3/CMakeFiles/tesk3_1.dir/depend

