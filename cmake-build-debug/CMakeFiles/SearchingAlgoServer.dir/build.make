# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/hodyah/Desktop/clion-2019.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/hodyah/Desktop/clion-2019.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hodyah/CLionProjects/SearchingAlgoServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hodyah/CLionProjects/SearchingAlgoServer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SearchingAlgoServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SearchingAlgoServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SearchingAlgoServer.dir/flags.make

CMakeFiles/SearchingAlgoServer.dir/main.cpp.o: CMakeFiles/SearchingAlgoServer.dir/flags.make
CMakeFiles/SearchingAlgoServer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hodyah/CLionProjects/SearchingAlgoServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SearchingAlgoServer.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SearchingAlgoServer.dir/main.cpp.o -c /home/hodyah/CLionProjects/SearchingAlgoServer/main.cpp

CMakeFiles/SearchingAlgoServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SearchingAlgoServer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hodyah/CLionProjects/SearchingAlgoServer/main.cpp > CMakeFiles/SearchingAlgoServer.dir/main.cpp.i

CMakeFiles/SearchingAlgoServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SearchingAlgoServer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hodyah/CLionProjects/SearchingAlgoServer/main.cpp -o CMakeFiles/SearchingAlgoServer.dir/main.cpp.s

CMakeFiles/SearchingAlgoServer.dir/MySerialServer.cpp.o: CMakeFiles/SearchingAlgoServer.dir/flags.make
CMakeFiles/SearchingAlgoServer.dir/MySerialServer.cpp.o: ../MySerialServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hodyah/CLionProjects/SearchingAlgoServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SearchingAlgoServer.dir/MySerialServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SearchingAlgoServer.dir/MySerialServer.cpp.o -c /home/hodyah/CLionProjects/SearchingAlgoServer/MySerialServer.cpp

CMakeFiles/SearchingAlgoServer.dir/MySerialServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SearchingAlgoServer.dir/MySerialServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hodyah/CLionProjects/SearchingAlgoServer/MySerialServer.cpp > CMakeFiles/SearchingAlgoServer.dir/MySerialServer.cpp.i

CMakeFiles/SearchingAlgoServer.dir/MySerialServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SearchingAlgoServer.dir/MySerialServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hodyah/CLionProjects/SearchingAlgoServer/MySerialServer.cpp -o CMakeFiles/SearchingAlgoServer.dir/MySerialServer.cpp.s

CMakeFiles/SearchingAlgoServer.dir/StringReverser.cpp.o: CMakeFiles/SearchingAlgoServer.dir/flags.make
CMakeFiles/SearchingAlgoServer.dir/StringReverser.cpp.o: ../StringReverser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hodyah/CLionProjects/SearchingAlgoServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SearchingAlgoServer.dir/StringReverser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SearchingAlgoServer.dir/StringReverser.cpp.o -c /home/hodyah/CLionProjects/SearchingAlgoServer/StringReverser.cpp

CMakeFiles/SearchingAlgoServer.dir/StringReverser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SearchingAlgoServer.dir/StringReverser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hodyah/CLionProjects/SearchingAlgoServer/StringReverser.cpp > CMakeFiles/SearchingAlgoServer.dir/StringReverser.cpp.i

CMakeFiles/SearchingAlgoServer.dir/StringReverser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SearchingAlgoServer.dir/StringReverser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hodyah/CLionProjects/SearchingAlgoServer/StringReverser.cpp -o CMakeFiles/SearchingAlgoServer.dir/StringReverser.cpp.s

CMakeFiles/SearchingAlgoServer.dir/FileCacheManager.cpp.o: CMakeFiles/SearchingAlgoServer.dir/flags.make
CMakeFiles/SearchingAlgoServer.dir/FileCacheManager.cpp.o: ../FileCacheManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hodyah/CLionProjects/SearchingAlgoServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SearchingAlgoServer.dir/FileCacheManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SearchingAlgoServer.dir/FileCacheManager.cpp.o -c /home/hodyah/CLionProjects/SearchingAlgoServer/FileCacheManager.cpp

CMakeFiles/SearchingAlgoServer.dir/FileCacheManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SearchingAlgoServer.dir/FileCacheManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hodyah/CLionProjects/SearchingAlgoServer/FileCacheManager.cpp > CMakeFiles/SearchingAlgoServer.dir/FileCacheManager.cpp.i

CMakeFiles/SearchingAlgoServer.dir/FileCacheManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SearchingAlgoServer.dir/FileCacheManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hodyah/CLionProjects/SearchingAlgoServer/FileCacheManager.cpp -o CMakeFiles/SearchingAlgoServer.dir/FileCacheManager.cpp.s

CMakeFiles/SearchingAlgoServer.dir/matrixSearchable.cpp.o: CMakeFiles/SearchingAlgoServer.dir/flags.make
CMakeFiles/SearchingAlgoServer.dir/matrixSearchable.cpp.o: ../matrixSearchable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hodyah/CLionProjects/SearchingAlgoServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SearchingAlgoServer.dir/matrixSearchable.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SearchingAlgoServer.dir/matrixSearchable.cpp.o -c /home/hodyah/CLionProjects/SearchingAlgoServer/matrixSearchable.cpp

CMakeFiles/SearchingAlgoServer.dir/matrixSearchable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SearchingAlgoServer.dir/matrixSearchable.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hodyah/CLionProjects/SearchingAlgoServer/matrixSearchable.cpp > CMakeFiles/SearchingAlgoServer.dir/matrixSearchable.cpp.i

CMakeFiles/SearchingAlgoServer.dir/matrixSearchable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SearchingAlgoServer.dir/matrixSearchable.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hodyah/CLionProjects/SearchingAlgoServer/matrixSearchable.cpp -o CMakeFiles/SearchingAlgoServer.dir/matrixSearchable.cpp.s

CMakeFiles/SearchingAlgoServer.dir/MyTestClientHandler.cpp.o: CMakeFiles/SearchingAlgoServer.dir/flags.make
CMakeFiles/SearchingAlgoServer.dir/MyTestClientHandler.cpp.o: ../MyTestClientHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hodyah/CLionProjects/SearchingAlgoServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SearchingAlgoServer.dir/MyTestClientHandler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SearchingAlgoServer.dir/MyTestClientHandler.cpp.o -c /home/hodyah/CLionProjects/SearchingAlgoServer/MyTestClientHandler.cpp

CMakeFiles/SearchingAlgoServer.dir/MyTestClientHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SearchingAlgoServer.dir/MyTestClientHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hodyah/CLionProjects/SearchingAlgoServer/MyTestClientHandler.cpp > CMakeFiles/SearchingAlgoServer.dir/MyTestClientHandler.cpp.i

CMakeFiles/SearchingAlgoServer.dir/MyTestClientHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SearchingAlgoServer.dir/MyTestClientHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hodyah/CLionProjects/SearchingAlgoServer/MyTestClientHandler.cpp -o CMakeFiles/SearchingAlgoServer.dir/MyTestClientHandler.cpp.s

# Object files for target SearchingAlgoServer
SearchingAlgoServer_OBJECTS = \
"CMakeFiles/SearchingAlgoServer.dir/main.cpp.o" \
"CMakeFiles/SearchingAlgoServer.dir/MySerialServer.cpp.o" \
"CMakeFiles/SearchingAlgoServer.dir/StringReverser.cpp.o" \
"CMakeFiles/SearchingAlgoServer.dir/FileCacheManager.cpp.o" \
"CMakeFiles/SearchingAlgoServer.dir/matrixSearchable.cpp.o" \
"CMakeFiles/SearchingAlgoServer.dir/MyTestClientHandler.cpp.o"

# External object files for target SearchingAlgoServer
SearchingAlgoServer_EXTERNAL_OBJECTS =

SearchingAlgoServer: CMakeFiles/SearchingAlgoServer.dir/main.cpp.o
SearchingAlgoServer: CMakeFiles/SearchingAlgoServer.dir/MySerialServer.cpp.o
SearchingAlgoServer: CMakeFiles/SearchingAlgoServer.dir/StringReverser.cpp.o
SearchingAlgoServer: CMakeFiles/SearchingAlgoServer.dir/FileCacheManager.cpp.o
SearchingAlgoServer: CMakeFiles/SearchingAlgoServer.dir/matrixSearchable.cpp.o
SearchingAlgoServer: CMakeFiles/SearchingAlgoServer.dir/MyTestClientHandler.cpp.o
SearchingAlgoServer: CMakeFiles/SearchingAlgoServer.dir/build.make
SearchingAlgoServer: CMakeFiles/SearchingAlgoServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hodyah/CLionProjects/SearchingAlgoServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable SearchingAlgoServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SearchingAlgoServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SearchingAlgoServer.dir/build: SearchingAlgoServer

.PHONY : CMakeFiles/SearchingAlgoServer.dir/build

CMakeFiles/SearchingAlgoServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SearchingAlgoServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SearchingAlgoServer.dir/clean

CMakeFiles/SearchingAlgoServer.dir/depend:
	cd /home/hodyah/CLionProjects/SearchingAlgoServer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hodyah/CLionProjects/SearchingAlgoServer /home/hodyah/CLionProjects/SearchingAlgoServer /home/hodyah/CLionProjects/SearchingAlgoServer/cmake-build-debug /home/hodyah/CLionProjects/SearchingAlgoServer/cmake-build-debug /home/hodyah/CLionProjects/SearchingAlgoServer/cmake-build-debug/CMakeFiles/SearchingAlgoServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SearchingAlgoServer.dir/depend

