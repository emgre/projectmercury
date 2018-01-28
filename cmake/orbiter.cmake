cmake_minimum_required (VERSION 3.8)

# Set the directories variables
set(ORBITER_DIR CACHE PATH "Path to Orbiter installation")
set(CMAKE_INSTALL_PREFIX ${ORBITER_DIR} CACHE PATH "Installation path" FORCE)
if(NOT ORBITER_DIR)
    message(SEND_ERROR "You must set ORBITER_DIR cache variable.")
endif()
if(NOT EXISTS ${ORBITER_DIR}/orbiter.exe)
    message(SEND_ERROR "ORBITER_DIR cache variable must point to a valid Orbiter installation.")
endif()

# Add Orbiter SDK imported target
add_library(orbitersdk STATIC IMPORTED GLOBAL)
set_property(TARGET orbitersdk PROPERTY IMPORTED_LOCATION ${ORBITER_DIR}/Orbitersdk/lib/orbiter.lib)
set_property(TARGET orbitersdk PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${ORBITER_DIR}/Orbitersdk/include)
set_property(TARGET orbitersdk PROPERTY INTERFACE_LINK_LIBRARIES ${ORBITER_DIR}/Orbitersdk/lib/orbiter.lib ${ORBITER_DIR}/Orbitersdk/lib/Orbitersdk.lib msvcrt.lib libcmtd.lib)

# Use static runtime.
set(compiler_flags
    CMAKE_CXX_FLAGS
    CMAKE_CXX_FLAGS_DEBUG
    CMAKE_CXX_FLAGS_RELEASE
    CMAKE_C_FLAGS
    CMAKE_C_FLAGS_DEBUG
    CMAKE_C_FLAGS_RELEASE
)
foreach(compiler_flag ${compiler_flags})
  string(REPLACE "/MD" "/MT" ${compiler_flag} "${${compiler_flag}}")
endforeach()
