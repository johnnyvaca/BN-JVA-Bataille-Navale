# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\CLion\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\CLion\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Johnny.VACA-JARAMILL\Documents\projets\BN-JVA-Bataille-Navale\development\bataille-navaleDev

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Johnny.VACA-JARAMILL\Documents\projets\BN-JVA-Bataille-Navale\development\bataille-navaleDev\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/bataille_navaleDev.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bataille_navaleDev.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bataille_navaleDev.dir/flags.make

CMakeFiles/bataille_navaleDev.dir/main.c.obj: CMakeFiles/bataille_navaleDev.dir/flags.make
CMakeFiles/bataille_navaleDev.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Johnny.VACA-JARAMILL\Documents\projets\BN-JVA-Bataille-Navale\development\bataille-navaleDev\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/bataille_navaleDev.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bataille_navaleDev.dir\main.c.obj   -c C:\Users\Johnny.VACA-JARAMILL\Documents\projets\BN-JVA-Bataille-Navale\development\bataille-navaleDev\main.c

CMakeFiles/bataille_navaleDev.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bataille_navaleDev.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Johnny.VACA-JARAMILL\Documents\projets\BN-JVA-Bataille-Navale\development\bataille-navaleDev\main.c > CMakeFiles\bataille_navaleDev.dir\main.c.i

CMakeFiles/bataille_navaleDev.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bataille_navaleDev.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Johnny.VACA-JARAMILL\Documents\projets\BN-JVA-Bataille-Navale\development\bataille-navaleDev\main.c -o CMakeFiles\bataille_navaleDev.dir\main.c.s

# Object files for target bataille_navaleDev
bataille_navaleDev_OBJECTS = \
"CMakeFiles/bataille_navaleDev.dir/main.c.obj"

# External object files for target bataille_navaleDev
bataille_navaleDev_EXTERNAL_OBJECTS =

bataille_navaleDev.exe: CMakeFiles/bataille_navaleDev.dir/main.c.obj
bataille_navaleDev.exe: CMakeFiles/bataille_navaleDev.dir/build.make
bataille_navaleDev.exe: CMakeFiles/bataille_navaleDev.dir/linklibs.rsp
bataille_navaleDev.exe: CMakeFiles/bataille_navaleDev.dir/objects1.rsp
bataille_navaleDev.exe: CMakeFiles/bataille_navaleDev.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Johnny.VACA-JARAMILL\Documents\projets\BN-JVA-Bataille-Navale\development\bataille-navaleDev\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bataille_navaleDev.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\bataille_navaleDev.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bataille_navaleDev.dir/build: bataille_navaleDev.exe

.PHONY : CMakeFiles/bataille_navaleDev.dir/build

CMakeFiles/bataille_navaleDev.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\bataille_navaleDev.dir\cmake_clean.cmake
.PHONY : CMakeFiles/bataille_navaleDev.dir/clean

CMakeFiles/bataille_navaleDev.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Johnny.VACA-JARAMILL\Documents\projets\BN-JVA-Bataille-Navale\development\bataille-navaleDev C:\Users\Johnny.VACA-JARAMILL\Documents\projets\BN-JVA-Bataille-Navale\development\bataille-navaleDev C:\Users\Johnny.VACA-JARAMILL\Documents\projets\BN-JVA-Bataille-Navale\development\bataille-navaleDev\cmake-build-debug C:\Users\Johnny.VACA-JARAMILL\Documents\projets\BN-JVA-Bataille-Navale\development\bataille-navaleDev\cmake-build-debug C:\Users\Johnny.VACA-JARAMILL\Documents\projets\BN-JVA-Bataille-Navale\development\bataille-navaleDev\cmake-build-debug\CMakeFiles\bataille_navaleDev.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bataille_navaleDev.dir/depend

