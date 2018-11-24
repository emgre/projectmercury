# Find header directory
find_path(ORBITER_SDK_INC_DIR
    NAMES Orbitersdk.h
    PATHS ${ORBITER_SDK_DIR}/include
)

# Find libraries
find_library(ORBITER_LIB
    NAMES orbiter.lib
    PATHS ${ORBITER_SDK_DIR}/lib
)
find_library(ORBITER_SDK_LIB
    NAMES Orbitersdk.lib
    PATHS ${ORBITER_SDK_DIR}/lib
)

# Handle standard arguments
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(OrbiterSDK
    REQUIRED_VARS ORBITER_SDK_INC_DIR ORBITER_LIB ORBITER_SDK_LIB
)

# Create targets
if(OrbiterSDK_FOUND)
    add_library(orbitersdk STATIC IMPORTED GLOBAL)
    set_property(TARGET orbitersdk PROPERTY IMPORTED_LOCATION ${ORBITER_LIB})
    set_property(TARGET orbitersdk PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${ORBITER_SDK_INC_DIR})
    set_property(TARGET orbitersdk PROPERTY INTERFACE_LINK_LIBRARIES ${ORBITER_LIB} ${ORBITER_SDK_LIB} -NODEFAULTLIB:msvcrt.lib)
endif()
