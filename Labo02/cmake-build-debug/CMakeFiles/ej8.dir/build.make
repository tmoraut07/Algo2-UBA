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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/Administrator/Desktop/Algo-2/AyED2-Labo02-Definicion_clases

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Administrator/Desktop/Algo-2/AyED2-Labo02-Definicion_clases/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ej8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ej8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ej8.dir/flags.make

CMakeFiles/ej8.dir/tests/test_recordatorios.cpp.o: CMakeFiles/ej8.dir/flags.make
CMakeFiles/ej8.dir/tests/test_recordatorios.cpp.o: ../tests/test_recordatorios.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Administrator/Desktop/Algo-2/AyED2-Labo02-Definicion_clases/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ej8.dir/tests/test_recordatorios.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ej8.dir/tests/test_recordatorios.cpp.o -c /mnt/c/Users/Administrator/Desktop/Algo-2/AyED2-Labo02-Definicion_clases/tests/test_recordatorios.cpp

CMakeFiles/ej8.dir/tests/test_recordatorios.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ej8.dir/tests/test_recordatorios.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Administrator/Desktop/Algo-2/AyED2-Labo02-Definicion_clases/tests/test_recordatorios.cpp > CMakeFiles/ej8.dir/tests/test_recordatorios.cpp.i

CMakeFiles/ej8.dir/tests/test_recordatorios.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ej8.dir/tests/test_recordatorios.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Administrator/Desktop/Algo-2/AyED2-Labo02-Definicion_clases/tests/test_recordatorios.cpp -o CMakeFiles/ej8.dir/tests/test_recordatorios.cpp.s

# Object files for target ej8
ej8_OBJECTS = \
"CMakeFiles/ej8.dir/tests/test_recordatorios.cpp.o"

# External object files for target ej8
ej8_EXTERNAL_OBJECTS =

ej8: CMakeFiles/ej8.dir/tests/test_recordatorios.cpp.o
ej8: CMakeFiles/ej8.dir/build.make
ej8: libgtest.a
ej8: libgtest_main.a
ej8: CMakeFiles/ej8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Administrator/Desktop/Algo-2/AyED2-Labo02-Definicion_clases/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ej8"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ej8.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ej8.dir/build: ej8

.PHONY : CMakeFiles/ej8.dir/build

CMakeFiles/ej8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ej8.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ej8.dir/clean

CMakeFiles/ej8.dir/depend:
	cd /mnt/c/Users/Administrator/Desktop/Algo-2/AyED2-Labo02-Definicion_clases/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Administrator/Desktop/Algo-2/AyED2-Labo02-Definicion_clases /mnt/c/Users/Administrator/Desktop/Algo-2/AyED2-Labo02-Definicion_clases /mnt/c/Users/Administrator/Desktop/Algo-2/AyED2-Labo02-Definicion_clases/cmake-build-debug /mnt/c/Users/Administrator/Desktop/Algo-2/AyED2-Labo02-Definicion_clases/cmake-build-debug /mnt/c/Users/Administrator/Desktop/Algo-2/AyED2-Labo02-Definicion_clases/cmake-build-debug/CMakeFiles/ej8.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ej8.dir/depend
