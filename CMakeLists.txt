cmake_minimum_required(VERSION 3.20)

################################################################################
# vcpkg
################################################################################
include (${CMAKE_SOURCE_DIR}/cmake/vcpkg.cmake)

project(OpenIT
    VERSION 1.0.1
    LANGUAGES CXX
    DESCRIPTION "OpenIT game"
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

################################################################################
# Options
################################################################################
option(OPENIT_BUILD_CLIENT "Build game client" ON)
option(OPENIT_BUILD_SERVER "Build game server" ON)

################################################################################
# Shared libraries
################################################################################

################################################################################
# Shared directories
################################################################################
set(SHARED_DIR          ${CMAKE_SOURCE_DIR}/shared)
set(SHARED_INCLUDE_DIR  ${SHARED_DIR}/include)
set(SHARED_SRC_DIR      ${SHARED_DIR}/src)
set(SHARED_RESOURCE_DIR ${SHARED_DIR}/resources)

################################################################################
# Shared sources
################################################################################
file(GLOB_RECURSE shared_src_cpp ${SHARED_SRC_DIR}/*.cpp)
file(GLOB_RECURSE shared_src_h   ${SHARED_SRC_DIR}/*.h)

set(shared_sources ${shared_src_cpp} ${shared_src_h})

################################################################################
# Sub-projects
################################################################################
add_subdirectory(projects)