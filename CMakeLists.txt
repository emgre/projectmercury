cmake_minimum_required (VERSION 3.15)

# Set the version number
set(version 6.0)
if(BUILD_NUMBER)
    set(version ${version}.${BUILD_NUMBER})
endif()

project (ProjectMercury VERSION ${version})

# Setup CMake for Orbiter
include(./cmake/orbiter.cmake)
find_package(OrbiterSDK REQUIRED)
find_package(XRSound REQUIRED)

message(STATUS "Building for ${ORBITER_EDITION} (${ORBITER_ARCH})")

# Add all the projects
add_subdirectory(./project_mercury)

# Packaging
set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_FILE_NAME ${PROJECT_NAME}-${PROJECT_VERSION})
include(CPack)
