# Name:        CMakeLists.txt
# Description: build of the TMNT runtime and its development tools
# Version:     0.1.0
# Created:     29-10-2026
# Modified:    29-10-2026
# Author:      Sebastian Toyos
cmake_minimum_required(VERSION 3.20)
project(tmnt C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Every executable lands in build/bin (TMNT_BIN_DIR), whatever the generator or configuration
set(TMNT_BIN_DIR ${CMAKE_SOURCE_DIR}/build/bin CACHE PATH "Where the executables go")
foreach(config IN ITEMS "" _DEBUG _RELEASE _RELWITHDEBINFO _MINSIZEREL)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY${config} ${TMNT_BIN_DIR})
endforeach()

if(MSVC)
	add_compile_options(/W3 /utf-8)
	add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
endif()

# The board as the program sees it, and the reader of the player's ROM set (for the tools that run the
# original code)
add_library(tmnt_runtime STATIC
	runtime/src/machine.c
	runtime/src/game_data.c
	runtime/src/rom_set.c
	runtime/src/inflate.c
)
target_include_directories(tmnt_runtime PUBLIC runtime/include PRIVATE runtime/src)

find_package(Python3 COMPONENTS Interpreter)

# The reference tools: the original program on MAME's cores (tools/core/konami/reference)
option(TMNT_REFERENCE_TOOLS "Build the MAME-based reference tools" ON)
if(TMNT_REFERENCE_TOOLS)
	if(NOT Python3_FOUND)
		message(FATAL_ERROR "The reference tools need Python 3 (MAME's 68000 core is written by m68000gen.py)")
	endif()
	set(K_GAME_RUNTIME tmnt_runtime)
	include(${CMAKE_SOURCE_DIR}/tools/core/konami/reference/reference.cmake)
endif()
