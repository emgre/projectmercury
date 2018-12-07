# Find header directory
find_path(XRSOUND_INC_DIR
    NAMES XRSound.h
    PATHS ${ORBITER_SDK_DIR}/XRSound
)

# Find library
find_library(XRSOUND_RELEASE_LIB
    NAMES XRSound.lib
    PATHS ${ORBITER_SDK_DIR}/XRSound
)
find_library(XRSOUND_DEBUG_LIB
    NAMES XRSoundD.lib
    PATHS ${ORBITER_SDK_DIR}/XRSound
)

# Handle standard arguments
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(XRSound
    REQUIRED_VARS XRSOUND_INC_DIR XRSOUND_RELEASE_LIB XRSOUND_DEBUG_LIB
)

# Create target
if(XRSound_FOUND)
    add_library(xrsound STATIC IMPORTED GLOBAL)
    set_property(TARGET xrsound PROPERTY IMPORTED_LOCATION_RELEASE ${XRSOUND_RELEASE_LIB})
    set_property(TARGET xrsound PROPERTY IMPORTED_LOCATION_DEBUG ${XRSOUND_DEBUG_LIB})
    set_property(TARGET xrsound PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${XRSOUND_INC_DIR})
endif()
