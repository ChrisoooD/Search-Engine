# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/137/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/137/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chris/桌面/search_engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chris/桌面/search_engine/cmake-build-debug

# Include any dependencies generated for this target.
include third_party/libfort/CMakeFiles/fort_dev.dir/depend.make

# Include the progress variables for this target.
include third_party/libfort/CMakeFiles/fort_dev.dir/progress.make

# Include the compile flags for this target's objects.
include third_party/libfort/CMakeFiles/fort_dev.dir/flags.make

third_party/libfort/CMakeFiles/fort_dev.dir/fort_impl.c.o: third_party/libfort/CMakeFiles/fort_dev.dir/flags.make
third_party/libfort/CMakeFiles/fort_dev.dir/fort_impl.c.o: ../third_party/libfort/fort_impl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chris/桌面/search_engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object third_party/libfort/CMakeFiles/fort_dev.dir/fort_impl.c.o"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fort_dev.dir/fort_impl.c.o   -c /home/chris/桌面/search_engine/third_party/libfort/fort_impl.c

third_party/libfort/CMakeFiles/fort_dev.dir/fort_impl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fort_dev.dir/fort_impl.c.i"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chris/桌面/search_engine/third_party/libfort/fort_impl.c > CMakeFiles/fort_dev.dir/fort_impl.c.i

third_party/libfort/CMakeFiles/fort_dev.dir/fort_impl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fort_dev.dir/fort_impl.c.s"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chris/桌面/search_engine/third_party/libfort/fort_impl.c -o CMakeFiles/fort_dev.dir/fort_impl.c.s

third_party/libfort/CMakeFiles/fort_dev.dir/vector.c.o: third_party/libfort/CMakeFiles/fort_dev.dir/flags.make
third_party/libfort/CMakeFiles/fort_dev.dir/vector.c.o: ../third_party/libfort/vector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chris/桌面/search_engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object third_party/libfort/CMakeFiles/fort_dev.dir/vector.c.o"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fort_dev.dir/vector.c.o   -c /home/chris/桌面/search_engine/third_party/libfort/vector.c

third_party/libfort/CMakeFiles/fort_dev.dir/vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fort_dev.dir/vector.c.i"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chris/桌面/search_engine/third_party/libfort/vector.c > CMakeFiles/fort_dev.dir/vector.c.i

third_party/libfort/CMakeFiles/fort_dev.dir/vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fort_dev.dir/vector.c.s"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chris/桌面/search_engine/third_party/libfort/vector.c -o CMakeFiles/fort_dev.dir/vector.c.s

third_party/libfort/CMakeFiles/fort_dev.dir/string_buffer.c.o: third_party/libfort/CMakeFiles/fort_dev.dir/flags.make
third_party/libfort/CMakeFiles/fort_dev.dir/string_buffer.c.o: ../third_party/libfort/string_buffer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chris/桌面/search_engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object third_party/libfort/CMakeFiles/fort_dev.dir/string_buffer.c.o"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fort_dev.dir/string_buffer.c.o   -c /home/chris/桌面/search_engine/third_party/libfort/string_buffer.c

third_party/libfort/CMakeFiles/fort_dev.dir/string_buffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fort_dev.dir/string_buffer.c.i"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chris/桌面/search_engine/third_party/libfort/string_buffer.c > CMakeFiles/fort_dev.dir/string_buffer.c.i

third_party/libfort/CMakeFiles/fort_dev.dir/string_buffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fort_dev.dir/string_buffer.c.s"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chris/桌面/search_engine/third_party/libfort/string_buffer.c -o CMakeFiles/fort_dev.dir/string_buffer.c.s

third_party/libfort/CMakeFiles/fort_dev.dir/properties.c.o: third_party/libfort/CMakeFiles/fort_dev.dir/flags.make
third_party/libfort/CMakeFiles/fort_dev.dir/properties.c.o: ../third_party/libfort/properties.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chris/桌面/search_engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object third_party/libfort/CMakeFiles/fort_dev.dir/properties.c.o"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fort_dev.dir/properties.c.o   -c /home/chris/桌面/search_engine/third_party/libfort/properties.c

third_party/libfort/CMakeFiles/fort_dev.dir/properties.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fort_dev.dir/properties.c.i"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chris/桌面/search_engine/third_party/libfort/properties.c > CMakeFiles/fort_dev.dir/properties.c.i

third_party/libfort/CMakeFiles/fort_dev.dir/properties.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fort_dev.dir/properties.c.s"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chris/桌面/search_engine/third_party/libfort/properties.c -o CMakeFiles/fort_dev.dir/properties.c.s

third_party/libfort/CMakeFiles/fort_dev.dir/cell.c.o: third_party/libfort/CMakeFiles/fort_dev.dir/flags.make
third_party/libfort/CMakeFiles/fort_dev.dir/cell.c.o: ../third_party/libfort/cell.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chris/桌面/search_engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object third_party/libfort/CMakeFiles/fort_dev.dir/cell.c.o"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fort_dev.dir/cell.c.o   -c /home/chris/桌面/search_engine/third_party/libfort/cell.c

third_party/libfort/CMakeFiles/fort_dev.dir/cell.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fort_dev.dir/cell.c.i"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chris/桌面/search_engine/third_party/libfort/cell.c > CMakeFiles/fort_dev.dir/cell.c.i

third_party/libfort/CMakeFiles/fort_dev.dir/cell.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fort_dev.dir/cell.c.s"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chris/桌面/search_engine/third_party/libfort/cell.c -o CMakeFiles/fort_dev.dir/cell.c.s

third_party/libfort/CMakeFiles/fort_dev.dir/row.c.o: third_party/libfort/CMakeFiles/fort_dev.dir/flags.make
third_party/libfort/CMakeFiles/fort_dev.dir/row.c.o: ../third_party/libfort/row.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chris/桌面/search_engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object third_party/libfort/CMakeFiles/fort_dev.dir/row.c.o"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fort_dev.dir/row.c.o   -c /home/chris/桌面/search_engine/third_party/libfort/row.c

third_party/libfort/CMakeFiles/fort_dev.dir/row.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fort_dev.dir/row.c.i"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chris/桌面/search_engine/third_party/libfort/row.c > CMakeFiles/fort_dev.dir/row.c.i

third_party/libfort/CMakeFiles/fort_dev.dir/row.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fort_dev.dir/row.c.s"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chris/桌面/search_engine/third_party/libfort/row.c -o CMakeFiles/fort_dev.dir/row.c.s

third_party/libfort/CMakeFiles/fort_dev.dir/table.c.o: third_party/libfort/CMakeFiles/fort_dev.dir/flags.make
third_party/libfort/CMakeFiles/fort_dev.dir/table.c.o: ../third_party/libfort/table.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chris/桌面/search_engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object third_party/libfort/CMakeFiles/fort_dev.dir/table.c.o"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fort_dev.dir/table.c.o   -c /home/chris/桌面/search_engine/third_party/libfort/table.c

third_party/libfort/CMakeFiles/fort_dev.dir/table.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fort_dev.dir/table.c.i"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chris/桌面/search_engine/third_party/libfort/table.c > CMakeFiles/fort_dev.dir/table.c.i

third_party/libfort/CMakeFiles/fort_dev.dir/table.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fort_dev.dir/table.c.s"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chris/桌面/search_engine/third_party/libfort/table.c -o CMakeFiles/fort_dev.dir/table.c.s

third_party/libfort/CMakeFiles/fort_dev.dir/fort_utils.c.o: third_party/libfort/CMakeFiles/fort_dev.dir/flags.make
third_party/libfort/CMakeFiles/fort_dev.dir/fort_utils.c.o: ../third_party/libfort/fort_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chris/桌面/search_engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object third_party/libfort/CMakeFiles/fort_dev.dir/fort_utils.c.o"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fort_dev.dir/fort_utils.c.o   -c /home/chris/桌面/search_engine/third_party/libfort/fort_utils.c

third_party/libfort/CMakeFiles/fort_dev.dir/fort_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fort_dev.dir/fort_utils.c.i"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chris/桌面/search_engine/third_party/libfort/fort_utils.c > CMakeFiles/fort_dev.dir/fort_utils.c.i

third_party/libfort/CMakeFiles/fort_dev.dir/fort_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fort_dev.dir/fort_utils.c.s"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chris/桌面/search_engine/third_party/libfort/fort_utils.c -o CMakeFiles/fort_dev.dir/fort_utils.c.s

third_party/libfort/CMakeFiles/fort_dev.dir/wcwidth.c.o: third_party/libfort/CMakeFiles/fort_dev.dir/flags.make
third_party/libfort/CMakeFiles/fort_dev.dir/wcwidth.c.o: ../third_party/libfort/wcwidth.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chris/桌面/search_engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object third_party/libfort/CMakeFiles/fort_dev.dir/wcwidth.c.o"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fort_dev.dir/wcwidth.c.o   -c /home/chris/桌面/search_engine/third_party/libfort/wcwidth.c

third_party/libfort/CMakeFiles/fort_dev.dir/wcwidth.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fort_dev.dir/wcwidth.c.i"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chris/桌面/search_engine/third_party/libfort/wcwidth.c > CMakeFiles/fort_dev.dir/wcwidth.c.i

third_party/libfort/CMakeFiles/fort_dev.dir/wcwidth.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fort_dev.dir/wcwidth.c.s"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chris/桌面/search_engine/third_party/libfort/wcwidth.c -o CMakeFiles/fort_dev.dir/wcwidth.c.s

# Object files for target fort_dev
fort_dev_OBJECTS = \
"CMakeFiles/fort_dev.dir/fort_impl.c.o" \
"CMakeFiles/fort_dev.dir/vector.c.o" \
"CMakeFiles/fort_dev.dir/string_buffer.c.o" \
"CMakeFiles/fort_dev.dir/properties.c.o" \
"CMakeFiles/fort_dev.dir/cell.c.o" \
"CMakeFiles/fort_dev.dir/row.c.o" \
"CMakeFiles/fort_dev.dir/table.c.o" \
"CMakeFiles/fort_dev.dir/fort_utils.c.o" \
"CMakeFiles/fort_dev.dir/wcwidth.c.o"

# External object files for target fort_dev
fort_dev_EXTERNAL_OBJECTS =

third_party/libfort/libfort_dev.a: third_party/libfort/CMakeFiles/fort_dev.dir/fort_impl.c.o
third_party/libfort/libfort_dev.a: third_party/libfort/CMakeFiles/fort_dev.dir/vector.c.o
third_party/libfort/libfort_dev.a: third_party/libfort/CMakeFiles/fort_dev.dir/string_buffer.c.o
third_party/libfort/libfort_dev.a: third_party/libfort/CMakeFiles/fort_dev.dir/properties.c.o
third_party/libfort/libfort_dev.a: third_party/libfort/CMakeFiles/fort_dev.dir/cell.c.o
third_party/libfort/libfort_dev.a: third_party/libfort/CMakeFiles/fort_dev.dir/row.c.o
third_party/libfort/libfort_dev.a: third_party/libfort/CMakeFiles/fort_dev.dir/table.c.o
third_party/libfort/libfort_dev.a: third_party/libfort/CMakeFiles/fort_dev.dir/fort_utils.c.o
third_party/libfort/libfort_dev.a: third_party/libfort/CMakeFiles/fort_dev.dir/wcwidth.c.o
third_party/libfort/libfort_dev.a: third_party/libfort/CMakeFiles/fort_dev.dir/build.make
third_party/libfort/libfort_dev.a: third_party/libfort/CMakeFiles/fort_dev.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chris/桌面/search_engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C static library libfort_dev.a"
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && $(CMAKE_COMMAND) -P CMakeFiles/fort_dev.dir/cmake_clean_target.cmake
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fort_dev.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
third_party/libfort/CMakeFiles/fort_dev.dir/build: third_party/libfort/libfort_dev.a

.PHONY : third_party/libfort/CMakeFiles/fort_dev.dir/build

third_party/libfort/CMakeFiles/fort_dev.dir/clean:
	cd /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort && $(CMAKE_COMMAND) -P CMakeFiles/fort_dev.dir/cmake_clean.cmake
.PHONY : third_party/libfort/CMakeFiles/fort_dev.dir/clean

third_party/libfort/CMakeFiles/fort_dev.dir/depend:
	cd /home/chris/桌面/search_engine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chris/桌面/search_engine /home/chris/桌面/search_engine/third_party/libfort /home/chris/桌面/search_engine/cmake-build-debug /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort /home/chris/桌面/search_engine/cmake-build-debug/third_party/libfort/CMakeFiles/fort_dev.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : third_party/libfort/CMakeFiles/fort_dev.dir/depend
