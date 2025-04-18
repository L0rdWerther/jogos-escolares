# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/lord_werther/CLionProjects/Luciana_Maria

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lord_werther/CLionProjects/Luciana_Maria

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/lord_werther/CLionProjects/Luciana_Maria/CMakeFiles /home/lord_werther/CLionProjects/Luciana_Maria//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/lord_werther/CLionProjects/Luciana_Maria/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named MeuProjeto

# Build rule for target.
MeuProjeto: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 MeuProjeto
.PHONY : MeuProjeto

# fast build rule for target.
MeuProjeto/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MeuProjeto.dir/build.make CMakeFiles/MeuProjeto.dir/build
.PHONY : MeuProjeto/fast

atleta.o: atleta.c.o
.PHONY : atleta.o

# target to build an object file
atleta.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MeuProjeto.dir/build.make CMakeFiles/MeuProjeto.dir/atleta.c.o
.PHONY : atleta.c.o

atleta.i: atleta.c.i
.PHONY : atleta.i

# target to preprocess a source file
atleta.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MeuProjeto.dir/build.make CMakeFiles/MeuProjeto.dir/atleta.c.i
.PHONY : atleta.c.i

atleta.s: atleta.c.s
.PHONY : atleta.s

# target to generate assembly for a file
atleta.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MeuProjeto.dir/build.make CMakeFiles/MeuProjeto.dir/atleta.c.s
.PHONY : atleta.c.s

equipe.o: equipe.c.o
.PHONY : equipe.o

# target to build an object file
equipe.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MeuProjeto.dir/build.make CMakeFiles/MeuProjeto.dir/equipe.c.o
.PHONY : equipe.c.o

equipe.i: equipe.c.i
.PHONY : equipe.i

# target to preprocess a source file
equipe.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MeuProjeto.dir/build.make CMakeFiles/MeuProjeto.dir/equipe.c.i
.PHONY : equipe.c.i

equipe.s: equipe.c.s
.PHONY : equipe.s

# target to generate assembly for a file
equipe.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MeuProjeto.dir/build.make CMakeFiles/MeuProjeto.dir/equipe.c.s
.PHONY : equipe.c.s

jogos.o: jogos.c.o
.PHONY : jogos.o

# target to build an object file
jogos.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MeuProjeto.dir/build.make CMakeFiles/MeuProjeto.dir/jogos.c.o
.PHONY : jogos.c.o

jogos.i: jogos.c.i
.PHONY : jogos.i

# target to preprocess a source file
jogos.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MeuProjeto.dir/build.make CMakeFiles/MeuProjeto.dir/jogos.c.i
.PHONY : jogos.c.i

jogos.s: jogos.c.s
.PHONY : jogos.s

# target to generate assembly for a file
jogos.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MeuProjeto.dir/build.make CMakeFiles/MeuProjeto.dir/jogos.c.s
.PHONY : jogos.c.s

main.o: main.c.o
.PHONY : main.o

# target to build an object file
main.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MeuProjeto.dir/build.make CMakeFiles/MeuProjeto.dir/main.c.o
.PHONY : main.c.o

main.i: main.c.i
.PHONY : main.i

# target to preprocess a source file
main.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MeuProjeto.dir/build.make CMakeFiles/MeuProjeto.dir/main.c.i
.PHONY : main.c.i

main.s: main.c.s
.PHONY : main.s

# target to generate assembly for a file
main.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MeuProjeto.dir/build.make CMakeFiles/MeuProjeto.dir/main.c.s
.PHONY : main.c.s

modalidade.o: modalidade.c.o
.PHONY : modalidade.o

# target to build an object file
modalidade.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MeuProjeto.dir/build.make CMakeFiles/MeuProjeto.dir/modalidade.c.o
.PHONY : modalidade.c.o

modalidade.i: modalidade.c.i
.PHONY : modalidade.i

# target to preprocess a source file
modalidade.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MeuProjeto.dir/build.make CMakeFiles/MeuProjeto.dir/modalidade.c.i
.PHONY : modalidade.c.i

modalidade.s: modalidade.c.s
.PHONY : modalidade.s

# target to generate assembly for a file
modalidade.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MeuProjeto.dir/build.make CMakeFiles/MeuProjeto.dir/modalidade.c.s
.PHONY : modalidade.c.s

torneio.o: torneio.c.o
.PHONY : torneio.o

# target to build an object file
torneio.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MeuProjeto.dir/build.make CMakeFiles/MeuProjeto.dir/torneio.c.o
.PHONY : torneio.c.o

torneio.i: torneio.c.i
.PHONY : torneio.i

# target to preprocess a source file
torneio.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MeuProjeto.dir/build.make CMakeFiles/MeuProjeto.dir/torneio.c.i
.PHONY : torneio.c.i

torneio.s: torneio.c.s
.PHONY : torneio.s

# target to generate assembly for a file
torneio.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MeuProjeto.dir/build.make CMakeFiles/MeuProjeto.dir/torneio.c.s
.PHONY : torneio.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... MeuProjeto"
	@echo "... atleta.o"
	@echo "... atleta.i"
	@echo "... atleta.s"
	@echo "... equipe.o"
	@echo "... equipe.i"
	@echo "... equipe.s"
	@echo "... jogos.o"
	@echo "... jogos.i"
	@echo "... jogos.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... modalidade.o"
	@echo "... modalidade.i"
	@echo "... modalidade.s"
	@echo "... torneio.o"
	@echo "... torneio.i"
	@echo "... torneio.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

