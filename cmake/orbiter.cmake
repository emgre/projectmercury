cmake_minimum_required(VERSION 3.19)

# Check that we are compiling for Windows
if(NOT WIN32)
    message(FATAL_ERROR "Orbiter projects must be compiled on Windows.")
endif()

# Set this directory as a module path so we can do find_package() for Orbiter stuff
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})

# ORBITER_DIR is used to install automatically to Orbiter and set the ORBITER_SDK_DIR
set(ORBITER_DIR CACHE PATH "Path to Orbiter installation")
if(ORBITER_DIR)
    if(NOT EXISTS ${ORBITER_DIR}/Orbiter_ng.exe)
        message(FATAL_ERROR "ORBITER_DIR cache variable must point to a valid Orbiter installation.")
    endif()
    set(CMAKE_INSTALL_PREFIX ${ORBITER_DIR} CACHE PATH "Installation path" FORCE)
    set(ORBITER_SDK_DIR ${ORBITER_DIR}/Orbitersdk CACHE PATH "Path to OrbiterSDK")
endif()

# ORBITER_SDK_DIR is used to detect the SDK
if((NOT ORBITER_SDK_DIR) OR (NOT EXISTS ${ORBITER_SDK_DIR}/lib/Orbitersdk.lib))
    message(FATAL_ERROR "ORBITER_SDK_DIR cache variable must point to a valid Orbiter SDK installation.")
endif()
