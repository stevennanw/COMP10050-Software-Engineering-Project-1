# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = "/Users/stevennanw/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/201.7223.86/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/stevennanw/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/201.7223.86/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/stevennanw/Desktop/DN201 Computer Science/19-20_Spring/COMP10050 Software Engineering Project 1/assignment3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/stevennanw/Desktop/DN201 Computer Science/19-20_Spring/COMP10050 Software Engineering Project 1/assignment3/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/assignment3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/assignment3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/assignment3.dir/flags.make

CMakeFiles/assignment3.dir/main.c.o: CMakeFiles/assignment3.dir/flags.make
CMakeFiles/assignment3.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/stevennanw/Desktop/DN201 Computer Science/19-20_Spring/COMP10050 Software Engineering Project 1/assignment3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/assignment3.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/assignment3.dir/main.c.o   -c "/Users/stevennanw/Desktop/DN201 Computer Science/19-20_Spring/COMP10050 Software Engineering Project 1/assignment3/main.c"

CMakeFiles/assignment3.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/assignment3.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/stevennanw/Desktop/DN201 Computer Science/19-20_Spring/COMP10050 Software Engineering Project 1/assignment3/main.c" > CMakeFiles/assignment3.dir/main.c.i

CMakeFiles/assignment3.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/assignment3.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/stevennanw/Desktop/DN201 Computer Science/19-20_Spring/COMP10050 Software Engineering Project 1/assignment3/main.c" -o CMakeFiles/assignment3.dir/main.c.s

CMakeFiles/assignment3.dir/avg_and_max.c.o: CMakeFiles/assignment3.dir/flags.make
CMakeFiles/assignment3.dir/avg_and_max.c.o: ../avg_and_max.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/stevennanw/Desktop/DN201 Computer Science/19-20_Spring/COMP10050 Software Engineering Project 1/assignment3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/assignment3.dir/avg_and_max.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/assignment3.dir/avg_and_max.c.o   -c "/Users/stevennanw/Desktop/DN201 Computer Science/19-20_Spring/COMP10050 Software Engineering Project 1/assignment3/avg_and_max.c"

CMakeFiles/assignment3.dir/avg_and_max.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/assignment3.dir/avg_and_max.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/stevennanw/Desktop/DN201 Computer Science/19-20_Spring/COMP10050 Software Engineering Project 1/assignment3/avg_and_max.c" > CMakeFiles/assignment3.dir/avg_and_max.c.i

CMakeFiles/assignment3.dir/avg_and_max.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/assignment3.dir/avg_and_max.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/stevennanw/Desktop/DN201 Computer Science/19-20_Spring/COMP10050 Software Engineering Project 1/assignment3/avg_and_max.c" -o CMakeFiles/assignment3.dir/avg_and_max.c.s

# Object files for target assignment3
assignment3_OBJECTS = \
"CMakeFiles/assignment3.dir/main.c.o" \
"CMakeFiles/assignment3.dir/avg_and_max.c.o"

# External object files for target assignment3
assignment3_EXTERNAL_OBJECTS =

assignment3: CMakeFiles/assignment3.dir/main.c.o
assignment3: CMakeFiles/assignment3.dir/avg_and_max.c.o
assignment3: CMakeFiles/assignment3.dir/build.make
assignment3: /usr/local/lib/libcunit.a
assignment3: CMakeFiles/assignment3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/stevennanw/Desktop/DN201 Computer Science/19-20_Spring/COMP10050 Software Engineering Project 1/assignment3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable assignment3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/assignment3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/assignment3.dir/build: assignment3

.PHONY : CMakeFiles/assignment3.dir/build

CMakeFiles/assignment3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/assignment3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/assignment3.dir/clean

CMakeFiles/assignment3.dir/depend:
	cd "/Users/stevennanw/Desktop/DN201 Computer Science/19-20_Spring/COMP10050 Software Engineering Project 1/assignment3/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/stevennanw/Desktop/DN201 Computer Science/19-20_Spring/COMP10050 Software Engineering Project 1/assignment3" "/Users/stevennanw/Desktop/DN201 Computer Science/19-20_Spring/COMP10050 Software Engineering Project 1/assignment3" "/Users/stevennanw/Desktop/DN201 Computer Science/19-20_Spring/COMP10050 Software Engineering Project 1/assignment3/cmake-build-debug" "/Users/stevennanw/Desktop/DN201 Computer Science/19-20_Spring/COMP10050 Software Engineering Project 1/assignment3/cmake-build-debug" "/Users/stevennanw/Desktop/DN201 Computer Science/19-20_Spring/COMP10050 Software Engineering Project 1/assignment3/cmake-build-debug/CMakeFiles/assignment3.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/assignment3.dir/depend
