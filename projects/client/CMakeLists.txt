cmake_minimum_required(VERSION 3.20)

project(Client
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "OpenIT game client"
)

################################################################################
# Libraries
################################################################################
find_library(Core NAMES OpenIT::Core)

################################################################################
# Directories
################################################################################
set(INCLUDE_DIR  ${PROJECT_SOURCE_DIR}/include)
set(SRC_DIR      ${PROJECT_SOURCE_DIR}/src)
set(RESOURCE_DIR ${CMAKE_SOURCE_DIR}/resources)

################################################################################
# Sources
################################################################################
file(GLOB_RECURSE src_cpp ${SRC_DIR}/*.cpp)
file(GLOB_RECURSE src_h   ${SRC_DIR}/*.h)

set(sources ${src_h} ${src_cpp} ${shared_sources})

################################################################################
# Target
################################################################################
IF (WIN32)
  add_executable(${PROJECT_NAME} WIN32 ${sources})
ELSE()
  add_executable(${PROJECT_NAME} ${sources})
ENDIF()

target_include_directories(${PROJECT_NAME}
  PRIVATE
    ${SHARED_INCLUDE_DIR}
    ${INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
  PRIVATE
    OpenIT::Core
)

################################################################################
# Compilation flags
################################################################################
include (${CMAKE_SOURCE_DIR}/cmake/compilation_flags.cmake)
