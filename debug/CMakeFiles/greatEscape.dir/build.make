# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.12.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.12.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/alexday/Desktop/GroupSeven

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alexday/Desktop/GroupSeven/debug

# Include any dependencies generated for this target.
include CMakeFiles/greatEscape.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/greatEscape.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/greatEscape.dir/flags.make

CMakeFiles/greatEscape.dir/bin/greatEscape.cpp.o: CMakeFiles/greatEscape.dir/flags.make
CMakeFiles/greatEscape.dir/bin/greatEscape.cpp.o: ../bin/greatEscape.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alexday/Desktop/GroupSeven/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/greatEscape.dir/bin/greatEscape.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/greatEscape.dir/bin/greatEscape.cpp.o -c /Users/alexday/Desktop/GroupSeven/bin/greatEscape.cpp

CMakeFiles/greatEscape.dir/bin/greatEscape.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/greatEscape.dir/bin/greatEscape.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alexday/Desktop/GroupSeven/bin/greatEscape.cpp > CMakeFiles/greatEscape.dir/bin/greatEscape.cpp.i

CMakeFiles/greatEscape.dir/bin/greatEscape.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/greatEscape.dir/bin/greatEscape.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alexday/Desktop/GroupSeven/bin/greatEscape.cpp -o CMakeFiles/greatEscape.dir/bin/greatEscape.cpp.s

# Object files for target greatEscape
greatEscape_OBJECTS = \
"CMakeFiles/greatEscape.dir/bin/greatEscape.cpp.o"

# External object files for target greatEscape
greatEscape_EXTERNAL_OBJECTS =

greatEscape: CMakeFiles/greatEscape.dir/bin/greatEscape.cpp.o
greatEscape: CMakeFiles/greatEscape.dir/build.make
greatEscape: Box2D/Box2D/libBox2D.a
greatEscape: libGroupSeven_core.a
greatEscape: Box2D/Box2D/libBox2D.a
greatEscape: CMakeFiles/greatEscape.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/alexday/Desktop/GroupSeven/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable greatEscape"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/greatEscape.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/greatEscape.dir/build: greatEscape

.PHONY : CMakeFiles/greatEscape.dir/build

CMakeFiles/greatEscape.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/greatEscape.dir/cmake_clean.cmake
.PHONY : CMakeFiles/greatEscape.dir/clean

CMakeFiles/greatEscape.dir/depend:
	cd /Users/alexday/Desktop/GroupSeven/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alexday/Desktop/GroupSeven /Users/alexday/Desktop/GroupSeven /Users/alexday/Desktop/GroupSeven/debug /Users/alexday/Desktop/GroupSeven/debug /Users/alexday/Desktop/GroupSeven/debug/CMakeFiles/greatEscape.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/greatEscape.dir/depend
