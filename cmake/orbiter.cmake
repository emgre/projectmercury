cmake_minimum_required (VERSION 3.8)

# Set the directories variables
set(ORBITER_DIR CACHE PATH "Path to Orbiter installation")
if(ORBITER_DIR)
    set(CMAKE_INSTALL_PREFIX ${ORBITER_DIR} CACHE PATH "Installation path" FORCE)
    if(NOT EXISTS ${ORBITER_DIR}/orbiter.exe)
        message(FATAL_ERROR "ORBITER_DIR cache variable must point to a valid Orbiter installation.")
    endif()
    set(ORBITER_SDK ${ORBITER_DIR}/Orbitersdk CACHE PATH "Path to OrbiterSDK")
endif()
if(NOT ORBITER_SDK)
    message(FATAL_ERROR "You must either set ORBITER_DIR or ORBITER_SDK cache variable.")
endif()
if(NOT EXISTS ${ORBITER_SDK}/lib/orbiter.lib)
    message(FATAL_ERROR "ORBITER_SDK cache variable must point to a valid OrbiterSDK directory.")
endif()


# Add Orbiter SDK imported target
add_library(orbitersdk STATIC IMPORTED GLOBAL)
set_property(TARGET orbitersdk PROPERTY IMPORTED_LOCATION ${ORBITER_SDK}/lib/orbiter.lib)
set_property(TARGET orbitersdk PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${ORBITER_SDK}/include)
set_property(TARGET orbitersdk PROPERTY INTERFACE_LINK_LIBRARIES ${ORBITER_SDK}/lib/orbiter.lib ${ORBITER_SDK}/lib/Orbitersdk.lib)

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

# Ignore pragma MSVCRT
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /NODEFAULTLIB:MSVCRT")
