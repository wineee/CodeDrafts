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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rew/CodeDrafts/CDib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rew/CodeDrafts/CDib

# Include any dependencies generated for this target.
include CMakeFiles/hello_cmake.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hello_cmake.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello_cmake.dir/flags.make

CMakeFiles/hello_cmake.dir/CDib.cpp.o: CMakeFiles/hello_cmake.dir/flags.make
CMakeFiles/hello_cmake.dir/CDib.cpp.o: CDib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rew/CodeDrafts/CDib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hello_cmake.dir/CDib.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hello_cmake.dir/CDib.cpp.o -c /home/rew/CodeDrafts/CDib/CDib.cpp

CMakeFiles/hello_cmake.dir/CDib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello_cmake.dir/CDib.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rew/CodeDrafts/CDib/CDib.cpp > CMakeFiles/hello_cmake.dir/CDib.cpp.i

CMakeFiles/hello_cmake.dir/CDib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello_cmake.dir/CDib.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rew/CodeDrafts/CDib/CDib.cpp -o CMakeFiles/hello_cmake.dir/CDib.cpp.s

# Object files for target hello_cmake
hello_cmake_OBJECTS = \
"CMakeFiles/hello_cmake.dir/CDib.cpp.o"

# External object files for target hello_cmake
hello_cmake_EXTERNAL_OBJECTS =

hello_cmake: CMakeFiles/hello_cmake.dir/CDib.cpp.o
hello_cmake: CMakeFiles/hello_cmake.dir/build.make
hello_cmake: CMakeFiles/hello_cmake.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rew/CodeDrafts/CDib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hello_cmake"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello_cmake.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hello_cmake.dir/build: hello_cmake

.PHONY : CMakeFiles/hello_cmake.dir/build

CMakeFiles/hello_cmake.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello_cmake.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello_cmake.dir/clean

CMakeFiles/hello_cmake.dir/depend:
	cd /home/rew/CodeDrafts/CDib && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rew/CodeDrafts/CDib /home/rew/CodeDrafts/CDib /home/rew/CodeDrafts/CDib /home/rew/CodeDrafts/CDib /home/rew/CodeDrafts/CDib/CMakeFiles/hello_cmake.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello_cmake.dir/depend

