cmake_minimum_required (VERSION 3.8)

# Shared
set(shared_headers
    ./include/common_addon.h
    ./include/Matrix.h
    ./include/Mercury_Capsule.h
    ./include/Mercury_Sequencer.h
    ./include/mercury_systems.h
    ./include/multi_stage5.h
    ./include/orbitelements.h
    ./include/resource.h
    ./include/Vectors.h
)
set(shared_src
    ./src/mercury_systems.cpp
    ./res/Resources.rc
)

# Atlas
set(atlas_headers
    ./include/Atlas.h
)
set(atlas_src
    ./src/Mercury_Atlas.cpp
)

# Redstone
set(redstone_headers
    ./include/Redstone.h
)
set(redstone_src
    ./src/Mercury_Redstone.cpp
)

# Find OpenGL
find_package(OpenGL REQUIRED)

add_library(MercuryAtlas SHARED ${shared_headers} ${shared_src} ${atlas_headers} ${atlas_src})
target_include_directories(MercuryAtlas PRIVATE ./include)
target_link_libraries(MercuryAtlas PRIVATE orbitersdk OpenGL::GL OpenGL::GLU)

add_library(MercuryRedstone SHARED ${shared_headers} ${shared_src} ${redstone_headers} ${redstone_src})
target_include_directories(MercuryRedstone PRIVATE ./include)
target_link_libraries(MercuryRedstone PRIVATE orbitersdk OpenGL::GL OpenGL::GLU)

# Installation
install(TARGETS MercuryAtlas RUNTIME DESTINATION Modules/ProjectMercury)
install(TARGETS MercuryRedstone RUNTIME DESTINATION Modules/ProjectMercury)
install(DIRECTORY ./res/config/ DESTINATION Config/Vessels)
install(DIRECTORY ./res/meshes/ DESTINATION Meshes)
install(DIRECTORY ./res/scenarios/ DESTINATION Scenarios/ProjectMercury)
install(DIRECTORY ./res/textures/ DESTINATION Textures)
