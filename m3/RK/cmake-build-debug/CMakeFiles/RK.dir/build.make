# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/152/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/152/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marvin/TP/Algorithms/m3/RK

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marvin/TP/Algorithms/m3/RK/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RK.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RK.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RK.dir/flags.make

CMakeFiles/RK.dir/main.cpp.o: CMakeFiles/RK.dir/flags.make
CMakeFiles/RK.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/TP/Algorithms/m3/RK/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RK.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RK.dir/main.cpp.o -c /home/marvin/TP/Algorithms/m3/RK/main.cpp

CMakeFiles/RK.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RK.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/TP/Algorithms/m3/RK/main.cpp > CMakeFiles/RK.dir/main.cpp.i

CMakeFiles/RK.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RK.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/TP/Algorithms/m3/RK/main.cpp -o CMakeFiles/RK.dir/main.cpp.s

# Object files for target RK
RK_OBJECTS = \
"CMakeFiles/RK.dir/main.cpp.o"

# External object files for target RK
RK_EXTERNAL_OBJECTS =

RK: CMakeFiles/RK.dir/main.cpp.o
RK: CMakeFiles/RK.dir/build.make
RK: CMakeFiles/RK.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marvin/TP/Algorithms/m3/RK/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RK"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RK.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RK.dir/build: RK

.PHONY : CMakeFiles/RK.dir/build

CMakeFiles/RK.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RK.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RK.dir/clean

CMakeFiles/RK.dir/depend:
	cd /home/marvin/TP/Algorithms/m3/RK/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marvin/TP/Algorithms/m3/RK /home/marvin/TP/Algorithms/m3/RK /home/marvin/TP/Algorithms/m3/RK/cmake-build-debug /home/marvin/TP/Algorithms/m3/RK/cmake-build-debug /home/marvin/TP/Algorithms/m3/RK/cmake-build-debug/CMakeFiles/RK.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RK.dir/depend
