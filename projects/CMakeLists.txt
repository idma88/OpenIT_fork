cmake_minimum_required(VERSION 3.20)

################################################################################
# Sub-projects
################################################################################
add_subdirectory(core)

if (OPENIT_BUILD_CLIENT)
  add_subdirectory(client)
endif()

if (OPENIT_BUILD_SERVER)
  add_subdirectory(server)
endif()