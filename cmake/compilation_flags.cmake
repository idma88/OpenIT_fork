################################################################################
# Compilation flags
################################################################################

################################################################################
# - Common flags by compiler
################################################################################
set(CXX_FLAGS_MSVC_      "/Zc:__cplusplus")
set(CXX_FLAGS_GNU_       "")
set(CXX_FLAGS_Clang_MSVC "")
set(CXX_FLAGS_Clang_GNU  "-Wno-undefined-var-template -Wno-switch")

################################################################################
# - Flags for Debug
################################################################################
set(CXX_FLAGS_DEBUG_MSVC_      "")
set(CXX_FLAGS_DEBUG_GNU_       "")
set(CXX_FLAGS_DEBUG_Clang_MSVC "")
set(CXX_FLAGS_DEBUG_Clang_GNU  "")

################################################################################
# - Flags for Release
################################################################################
set(CXX_FLAGS_RELEASE_MSVC_      "/O2 /Ob2 /Oi /Ot")
set(CXX_FLAGS_RELEASE_GNU_       "-O3")
set(CXX_FLAGS_RELEASE_Clang_MSVC "/O2 /Ob2 /Oi /Ot")
set(CXX_FLAGS_RELEASE_Clang_GNU  "-O3")


if (CMAKE_BUILD_TYPE STREQUAL "" OR CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(BUILD_TYPE "DEBUG")
elseif (CMAKE_BUILD_TYPE STREQUAL "Release" OR CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
  set(BUILD_TYPE "RELEASE")
endif()

set(CXX_FLAGS_VARIANT     "CXX_FLAGS_${CMAKE_CXX_COMPILER_ID}_${CMAKE_CXX_COMPILER_FRONTEND_VARIANT}")
set(CXX_FLAGS_VARIANT_EXT "CXX_FLAGS_${BUILD_TYPE}_${CMAKE_CXX_COMPILER_ID}_${CMAKE_CXX_COMPILER_FRONTEND_VARIANT}")
