cmake_minimum_required(VERSION 3.19)

# Find header directory
find_path(ORBITER_SDK_INC_DIR
    NAMES Orbitersdk.h
    PATHS ${ORBITER_SDK_DIR}/include
    NO_DEFAULT_PATH
)

# Find libraries
find_library(ORBITER_LIB
    NAMES orbiter.lib
    PATHS ${ORBITER_SDK_DIR}/lib
    NO_DEFAULT_PATH
)
find_library(ORBITER_SDK_LIB
    NAMES Orbitersdk.lib
    PATHS ${ORBITER_SDK_DIR}/lib
    NO_DEFAULT_PATH
)

# Determine which version we are running
find_library(_ORBITER_GDI_CLIENT_LIB
    NAMES GDIClient.lib
    PATHS ${ORBITER_SDK_DIR}/lib
    NO_DEFAULT_PATH
    NO_CACHE
)
if(_ORBITER_GDI_CLIENT_LIB)
    set(ORBITER_EDITION "Orbiter2016")
else()
    set(ORBITER_EDITION "OpenOrbiter")
endif()

# Determine architecture of the SDK
execute_process(COMMAND dumpbin.exe /headers ${ORBITER_SDK_LIB}
    OUTPUT_VARIABLE _ORBITER_DUMP_BIN_OUTPUT
    COMMAND_ERROR_IS_FATAL ANY
)
if(_ORBITER_DUMP_BIN_OUTPUT MATCHES ".+machine \\(x64\\).+")
    set(ORBITER_ARCH "x64")
else()
    set(ORBITER_ARCH "x86")
endif()

# Validate that the architecture fits
if((CMAKE_SIZEOF_VOID_P EQUAL 4) AND (ORBITER_ARCH STREQUAL "x64"))
    message(FATAL_ERROR "Incompatible Orbiter SDK. Trying to build in 32-bit with a 64-bit SDK.")
endif()
if((CMAKE_SIZEOF_VOID_P EQUAL 8) AND (ORBITER_ARCH STREQUAL "x86"))
    message(FATAL_ERROR "Incompatible Orbiter SDK. Trying to build in 64-bit with a 32-bit SDK.")
endif()

# Handle standard arguments
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(OrbiterSDK
    REQUIRED_VARS ORBITER_SDK_INC_DIR;ORBITER_LIB;ORBITER_SDK_LIB
)

# Create targets
if(OrbiterSDK_FOUND)
    # Since we link with a static library, we need to match its CRT config
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")

    # Define a CMake library
    add_library(orbitersdk STATIC IMPORTED GLOBAL)
    set_property(TARGET orbitersdk PROPERTY IMPORTED_LOCATION ${ORBITER_LIB})
    set_property(TARGET orbitersdk PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${ORBITER_SDK_INC_DIR})
    set_property(TARGET orbitersdk PROPERTY INTERFACE_LINK_LIBRARIES ${ORBITER_LIB} ${ORBITER_SDK_LIB})
endif()

# Cleanup
unset(_ORBITER_GDI_CLIENT_LIB)
unset(_ORBITER_DUMP_BIN_OUTPUT)
