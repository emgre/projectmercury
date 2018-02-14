cmake_minimum_required (VERSION 3.8)

# Set the version number
set(version 6.0)
if(BUILD_NUMBER)
    set(version ${version}.${BUILD_NUMBER})
endif()

project (ProjectMercury VERSION ${version})

# Preserve folders for Visual Studio
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Orbiter SDK
include(./cmake/orbiter.cmake)

# Add all the projects
add_subdirectory(./project_mercury)

# Packaging
set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_FILE_NAME ${PROJECT_NAME}-${PROJECT_VERSION})
include(CPack)
