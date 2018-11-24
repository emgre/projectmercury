cmake_minimum_required (VERSION 3.8)

# Check that we are compiling for Windows 32-bit
if((NOT WIN32) OR (NOT "${CMAKE_SIZEOF_VOID_P}" STREQUAL "4"))
    message(FATAL_ERROR "Orbiter projects must be compiled on Windows targeting x86 architecture.")
endif()

# Set the directories variables
set(ORBITER_DIR CACHE PATH "Path to Orbiter installation")
if(ORBITER_DIR)
    set(CMAKE_INSTALL_PREFIX ${ORBITER_DIR} CACHE PATH "Installation path" FORCE)
    if(NOT EXISTS ${ORBITER_DIR}/orbiter.exe)
        message(FATAL_ERROR "ORBITER_DIR cache variable must point to a valid Orbiter installation.")
    endif()
    set(ORBITER_SDK_DIR ${ORBITER_DIR}/Orbitersdk CACHE PATH "Path to OrbiterSDK")
endif()
if(NOT ORBITER_SDK_DIR)
    message(FATAL_ERROR "You must either set ORBITER_DIR or ORBITER_SDK_DIR cache variable.")
endif()

# Use static runtime
set(compiler_flags
    CMAKE_CXX_FLAGS
    CMAKE_CXX_FLAGS_DEBUG
    CMAKE_CXX_FLAGS_MINSIZEREL
    CMAKE_CXX_FLAGS_RELEASE
    CMAKE_CXX_FLAGS_RELWITHDEBINFO
    CMAKE_C_FLAGS
    CMAKE_C_FLAGS_DEBUG
    CMAKE_C_FLAGS_MINSIZEREL
    CMAKE_C_FLAGS_RELEASE
    CMAKE_C_FLAGS_RELWITHDEBINFO
)
foreach(compiler_flag ${compiler_flags})
    string(REPLACE "/MD" "/MT" ${compiler_flag} "${${compiler_flag}}")
endforeach()
