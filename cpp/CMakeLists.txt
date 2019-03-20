cmake_minimum_required(VERSION 3.7)
project(algorithms CXX)

set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

message(STATUS "CMAKE_CXX_STANDARD: ${CMAKE_CXX_STANDARD}")
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message(STATUS "ENVIRONMENT VARIABLES:")
message(STATUS "    DYLD_LIBRARY_PATH: $ENV{DYLD_LIBRARY_PATH}")

get_filename_component(ALG_ROOT_DIR . ABSOLUTE)
get_filename_component(ALG_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR} ABSOLUTE)
get_filename_component(ALG_SRC_DIR src ABSOLUTE)

if(CMAKE_BUILD_TYPE STREQUAL "Debug") # only when CMAKE_BUILD_TYPE is "Debug"
  # Address sanitizer
  add_compile_options(-O0 -Wno-unused-variable -Wno-unused-private-field -fno-omit-frame-pointer -O1 -fsanitize=address -fsanitize=leak)
  link_libraries(-fsanitize=address -fsanitize=leak)
endif()

include_directories(BEFORE
  ${ALG_SRC_DIR}
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ALG_BUILD_SRC_DIR})
set(CMAKE_SRCRARY_OUTPUT_DIRECTORY ${ALG_BUILD_SRC_DIR})
link_directories(${ALG_BUILD_SRC_DIR})

add_subdirectory(${ALG_SRC_DIR})