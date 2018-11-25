cmake_minimum_required (VERSION 3.8)

set(sound_test_headers
    ./src/MyVessel.h
)
set(sound_test_src
    ./src/main.cpp

    ./src/MyVessel.cpp
)

add_library(SoundTest SHARED ${sound_test_headers} ${sound_test_src})
target_include_directories(SoundTest PRIVATE ./src)
target_link_libraries(SoundTest PRIVATE orbitersdk xrsound)

# Installation
install(TARGETS SoundTest RUNTIME DESTINATION Modules/SoundTest)
install(DIRECTORY ./res/config/ DESTINATION Config/Vessels)
install(DIRECTORY ./res/scenarios/ DESTINATION Scenarios/SoundTest)
install(DIRECTORY ./res/sounds/ DESTINATION XRSound/SoundTest)
