cmake_minimum_required (VERSION 3.8)

# Set the version number
set(version 6.0)
if(BUILD_NUMBER)
    set(version ${version}.${BUILD_NUMBER})
endif()

project (ProjectMercury VERSION ${version})

# Preserve folders for Visual Studio
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Setup CMake for Orbiter
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
include(./cmake/orbiter.cmake)
find_package(OrbiterSDK REQUIRED)
find_package(XRSound REQUIRED)

# Add all the projects
add_subdirectory(./project_mercury)
add_subdirectory(./sound_test)

# Packaging
set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_FILE_NAME ${PROJECT_NAME}-${PROJECT_VERSION})
include(CPack)
