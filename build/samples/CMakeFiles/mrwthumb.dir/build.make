# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_SOURCE_DIR = /mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/build

# Include any dependencies generated for this target.
include samples/CMakeFiles/mrwthumb.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include samples/CMakeFiles/mrwthumb.dir/compiler_depend.make

# Include the progress variables for this target.
include samples/CMakeFiles/mrwthumb.dir/progress.make

# Include the compile flags for this target's objects.
include samples/CMakeFiles/mrwthumb.dir/flags.make

samples/CMakeFiles/mrwthumb.dir/mrwthumb.cpp.o: samples/CMakeFiles/mrwthumb.dir/flags.make
samples/CMakeFiles/mrwthumb.dir/mrwthumb.cpp.o: ../samples/mrwthumb.cpp
samples/CMakeFiles/mrwthumb.dir/mrwthumb.cpp.o: samples/CMakeFiles/mrwthumb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object samples/CMakeFiles/mrwthumb.dir/mrwthumb.cpp.o"
	cd /mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/build/samples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT samples/CMakeFiles/mrwthumb.dir/mrwthumb.cpp.o -MF CMakeFiles/mrwthumb.dir/mrwthumb.cpp.o.d -o CMakeFiles/mrwthumb.dir/mrwthumb.cpp.o -c /mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/samples/mrwthumb.cpp

samples/CMakeFiles/mrwthumb.dir/mrwthumb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mrwthumb.dir/mrwthumb.cpp.i"
	cd /mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/build/samples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/samples/mrwthumb.cpp > CMakeFiles/mrwthumb.dir/mrwthumb.cpp.i

samples/CMakeFiles/mrwthumb.dir/mrwthumb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mrwthumb.dir/mrwthumb.cpp.s"
	cd /mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/build/samples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/samples/mrwthumb.cpp -o CMakeFiles/mrwthumb.dir/mrwthumb.cpp.s

# Object files for target mrwthumb
mrwthumb_OBJECTS = \
"CMakeFiles/mrwthumb.dir/mrwthumb.cpp.o"

# External object files for target mrwthumb
mrwthumb_EXTERNAL_OBJECTS =

bin/mrwthumb: samples/CMakeFiles/mrwthumb.dir/mrwthumb.cpp.o
bin/mrwthumb: samples/CMakeFiles/mrwthumb.dir/build.make
bin/mrwthumb: lib/libexiv2.so.0.27.99.0
bin/mrwthumb: /usr/lib/x86_64-linux-gnu/libz.so
bin/mrwthumb: samples/CMakeFiles/mrwthumb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/mrwthumb"
	cd /mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/build/samples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mrwthumb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
samples/CMakeFiles/mrwthumb.dir/build: bin/mrwthumb
.PHONY : samples/CMakeFiles/mrwthumb.dir/build

samples/CMakeFiles/mrwthumb.dir/clean:
	cd /mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/build/samples && $(CMAKE_COMMAND) -P CMakeFiles/mrwthumb.dir/cmake_clean.cmake
.PHONY : samples/CMakeFiles/mrwthumb.dir/clean

samples/CMakeFiles/mrwthumb.dir/depend:
	cd /mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic /mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/samples /mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/build /mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/build/samples /mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/build/samples/CMakeFiles/mrwthumb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : samples/CMakeFiles/mrwthumb.dir/depend
