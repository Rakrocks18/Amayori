# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/rakshit_shah/amayori

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rakshit_shah/amayori/build

# Include any dependencies generated for this target.
include CMakeFiles/amayori.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/amayori.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/amayori.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/amayori.dir/flags.make

CMakeFiles/amayori.dir/src/main.cpp.o: CMakeFiles/amayori.dir/flags.make
CMakeFiles/amayori.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/amayori.dir/src/main.cpp.o: CMakeFiles/amayori.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rakshit_shah/amayori/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/amayori.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/amayori.dir/src/main.cpp.o -MF CMakeFiles/amayori.dir/src/main.cpp.o.d -o CMakeFiles/amayori.dir/src/main.cpp.o -c /home/rakshit_shah/amayori/src/main.cpp

CMakeFiles/amayori.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/amayori.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rakshit_shah/amayori/src/main.cpp > CMakeFiles/amayori.dir/src/main.cpp.i

CMakeFiles/amayori.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/amayori.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rakshit_shah/amayori/src/main.cpp -o CMakeFiles/amayori.dir/src/main.cpp.s

# Object files for target amayori
amayori_OBJECTS = \
"CMakeFiles/amayori.dir/src/main.cpp.o"

# External object files for target amayori
amayori_EXTERNAL_OBJECTS =

amayori: CMakeFiles/amayori.dir/src/main.cpp.o
amayori: CMakeFiles/amayori.dir/build.make
amayori: CMakeFiles/amayori.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rakshit_shah/amayori/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable amayori"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/amayori.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/amayori.dir/build: amayori
.PHONY : CMakeFiles/amayori.dir/build

CMakeFiles/amayori.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/amayori.dir/cmake_clean.cmake
.PHONY : CMakeFiles/amayori.dir/clean

CMakeFiles/amayori.dir/depend:
	cd /home/rakshit_shah/amayori/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rakshit_shah/amayori /home/rakshit_shah/amayori /home/rakshit_shah/amayori/build /home/rakshit_shah/amayori/build /home/rakshit_shah/amayori/build/CMakeFiles/amayori.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/amayori.dir/depend

