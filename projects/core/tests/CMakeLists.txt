cmake_minimum_required(VERSION 3.20)

project(CoreTests
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "Tests OpenIT core game library"
)

enable_testing()

################################################################################
# Libraries
################################################################################
find_package(GTest REQUIRED)
find_library(Core NAMES OpenIT::Core)

################################################################################
# Sources
################################################################################
file(GLOB_RECURSE src_h *.h)
file(GLOB_RECURSE src_cpp *.cpp)

set(sources ${src_h} ${src_cpp})

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${sources})

add_test(
  NAME ${PROJECT_NAME} 
  COMMAND ${PROJECT_NAME}
)

target_include_directories(${PROJECT_NAME}
  PRIVATE
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME} 
  PUBLIC
    OpenIT::Core
  PRIVATE
    GTest::GTest GTest::Main
)

################################################################################
# Compilation flags
################################################################################
include (${CMAKE_SOURCE_DIR}/cmake/compilation_flags.cmake)