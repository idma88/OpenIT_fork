cmake_minimum_required(VERSION 3.20)

project(Core
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "OpenIT core game library"
)

################################################################################
# Options
################################################################################
option(BUILD_OPENIT_CORE_TEST "Build tests for OpenIT core game library" ON)

################################################################################
# Libraries
################################################################################

################################################################################
# Directories
################################################################################
set(INCLUDE_DIR  ${PROJECT_SOURCE_DIR}/include)
set(SRC_DIR      ${PROJECT_SOURCE_DIR}/src)

################################################################################
# Sources
################################################################################
file(GLOB_RECURSE src_h   ${SRC_DIR}/*.h)
file(GLOB_RECURSE src_cpp ${SRC_DIR}/*.cpp)

set(sources ${src_h} ${src_cpp} ${shared_sources})

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${sources})
add_library(OpenIT::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
  PRIVATE
    ${SHARED_INCLUDE_DIR}
    ${INCLUDE_DIR}
  PUBLIC
    $<BUILD_INTERFACE:${INCLUDE_DIR}>
)


target_link_libraries(${PROJECT_NAME} 
  PUBLIC
  PRIVATE
)

################################################################################
# Compilation flags
################################################################################
include (${CMAKE_SOURCE_DIR}/cmake/compilation_flags.cmake)

################################################################################
# Compilation flags
################################################################################
if (BUILD_OPENIT_CORE_TEST)
  add_subdirectory(tests)
endif()