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
include CMakeFiles/hello_cmakeDome.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hello_cmakeDome.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello_cmakeDome.dir/flags.make

CMakeFiles/hello_cmakeDome.dir/CDib.cpp.o: CMakeFiles/hello_cmakeDome.dir/flags.make
CMakeFiles/hello_cmakeDome.dir/CDib.cpp.o: CDib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rew/CodeDrafts/CDib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hello_cmakeDome.dir/CDib.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hello_cmakeDome.dir/CDib.cpp.o -c /home/rew/CodeDrafts/CDib/CDib.cpp

CMakeFiles/hello_cmakeDome.dir/CDib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello_cmakeDome.dir/CDib.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rew/CodeDrafts/CDib/CDib.cpp > CMakeFiles/hello_cmakeDome.dir/CDib.cpp.i

CMakeFiles/hello_cmakeDome.dir/CDib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello_cmakeDome.dir/CDib.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rew/CodeDrafts/CDib/CDib.cpp -o CMakeFiles/hello_cmakeDome.dir/CDib.cpp.s

# Object files for target hello_cmakeDome
hello_cmakeDome_OBJECTS = \
"CMakeFiles/hello_cmakeDome.dir/CDib.cpp.o"

# External object files for target hello_cmakeDome
hello_cmakeDome_EXTERNAL_OBJECTS =

hello_cmakeDome: CMakeFiles/hello_cmakeDome.dir/CDib.cpp.o
hello_cmakeDome: CMakeFiles/hello_cmakeDome.dir/build.make
hello_cmakeDome: CMakeFiles/hello_cmakeDome.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rew/CodeDrafts/CDib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hello_cmakeDome"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello_cmakeDome.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hello_cmakeDome.dir/build: hello_cmakeDome

.PHONY : CMakeFiles/hello_cmakeDome.dir/build

CMakeFiles/hello_cmakeDome.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello_cmakeDome.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello_cmakeDome.dir/clean

CMakeFiles/hello_cmakeDome.dir/depend:
	cd /home/rew/CodeDrafts/CDib && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rew/CodeDrafts/CDib /home/rew/CodeDrafts/CDib /home/rew/CodeDrafts/CDib /home/rew/CodeDrafts/CDib /home/rew/CodeDrafts/CDib/CMakeFiles/hello_cmakeDome.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello_cmakeDome.dir/depend

