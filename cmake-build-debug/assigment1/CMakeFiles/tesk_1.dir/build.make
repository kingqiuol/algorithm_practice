# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.6

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\clion\CLion 2016.3.5\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\clion\CLion 2016.3.5\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\jinqiu\Desktop\tesk

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jinqiu\Desktop\tesk\cmake-build-debug

# Include any dependencies generated for this target.
include assigment1/CMakeFiles/tesk_1.dir/depend.make

# Include the progress variables for this target.
include assigment1/CMakeFiles/tesk_1.dir/progress.make

# Include the compile flags for this target's objects.
include assigment1/CMakeFiles/tesk_1.dir/flags.make

assigment1/CMakeFiles/tesk_1.dir/array.cpp.obj: assigment1/CMakeFiles/tesk_1.dir/flags.make
assigment1/CMakeFiles/tesk_1.dir/array.cpp.obj: ../assigment1/array.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jinqiu\Desktop\tesk\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object assigment1/CMakeFiles/tesk_1.dir/array.cpp.obj"
	cd /d C:\Users\jinqiu\Desktop\tesk\cmake-build-debug\assigment1 && D:\vim\mingw\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tesk_1.dir\array.cpp.obj -c C:\Users\jinqiu\Desktop\tesk\assigment1\array.cpp

assigment1/CMakeFiles/tesk_1.dir/array.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tesk_1.dir/array.cpp.i"
	cd /d C:\Users\jinqiu\Desktop\tesk\cmake-build-debug\assigment1 && D:\vim\mingw\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jinqiu\Desktop\tesk\assigment1\array.cpp > CMakeFiles\tesk_1.dir\array.cpp.i

assigment1/CMakeFiles/tesk_1.dir/array.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tesk_1.dir/array.cpp.s"
	cd /d C:\Users\jinqiu\Desktop\tesk\cmake-build-debug\assigment1 && D:\vim\mingw\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jinqiu\Desktop\tesk\assigment1\array.cpp -o CMakeFiles\tesk_1.dir\array.cpp.s

assigment1/CMakeFiles/tesk_1.dir/array.cpp.obj.requires:

.PHONY : assigment1/CMakeFiles/tesk_1.dir/array.cpp.obj.requires

assigment1/CMakeFiles/tesk_1.dir/array.cpp.obj.provides: assigment1/CMakeFiles/tesk_1.dir/array.cpp.obj.requires
	$(MAKE) -f assigment1\CMakeFiles\tesk_1.dir\build.make assigment1/CMakeFiles/tesk_1.dir/array.cpp.obj.provides.build
.PHONY : assigment1/CMakeFiles/tesk_1.dir/array.cpp.obj.provides

assigment1/CMakeFiles/tesk_1.dir/array.cpp.obj.provides.build: assigment1/CMakeFiles/tesk_1.dir/array.cpp.obj


# Object files for target tesk_1
tesk_1_OBJECTS = \
"CMakeFiles/tesk_1.dir/array.cpp.obj"

# External object files for target tesk_1
tesk_1_EXTERNAL_OBJECTS =

assigment1/tesk_1.exe: assigment1/CMakeFiles/tesk_1.dir/array.cpp.obj
assigment1/tesk_1.exe: assigment1/CMakeFiles/tesk_1.dir/build.make
assigment1/tesk_1.exe: assigment1/CMakeFiles/tesk_1.dir/linklibs.rsp
assigment1/tesk_1.exe: assigment1/CMakeFiles/tesk_1.dir/objects1.rsp
assigment1/tesk_1.exe: assigment1/CMakeFiles/tesk_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\jinqiu\Desktop\tesk\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tesk_1.exe"
	cd /d C:\Users\jinqiu\Desktop\tesk\cmake-build-debug\assigment1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tesk_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
assigment1/CMakeFiles/tesk_1.dir/build: assigment1/tesk_1.exe

.PHONY : assigment1/CMakeFiles/tesk_1.dir/build

assigment1/CMakeFiles/tesk_1.dir/requires: assigment1/CMakeFiles/tesk_1.dir/array.cpp.obj.requires

.PHONY : assigment1/CMakeFiles/tesk_1.dir/requires

assigment1/CMakeFiles/tesk_1.dir/clean:
	cd /d C:\Users\jinqiu\Desktop\tesk\cmake-build-debug\assigment1 && $(CMAKE_COMMAND) -P CMakeFiles\tesk_1.dir\cmake_clean.cmake
.PHONY : assigment1/CMakeFiles/tesk_1.dir/clean

assigment1/CMakeFiles/tesk_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jinqiu\Desktop\tesk C:\Users\jinqiu\Desktop\tesk\assigment1 C:\Users\jinqiu\Desktop\tesk\cmake-build-debug C:\Users\jinqiu\Desktop\tesk\cmake-build-debug\assigment1 C:\Users\jinqiu\Desktop\tesk\cmake-build-debug\assigment1\CMakeFiles\tesk_1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : assigment1/CMakeFiles/tesk_1.dir/depend

