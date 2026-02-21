cmake_minimum_required(VERSION 3.22)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
project(EnergySystemSimulation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#SFML
include(FetchContent)
FetchContent_Declare(
    sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
)
FetchContent_MakeAvailable(sfml)

#TGUI
set(TGUI_BACKEND SFML_GRAPHICS CACHE STRING "" FORCE)
set(TGUI_BUILD_FRAMEWORK FALSE CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    tgui
    GIT_REPOSITORY https://github.com/texus/TGUI.git
    GIT_TAG v1.7.0
)
FetchContent_MakeAvailable(tgui)

file(GLOB SOURCE_FILES 
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/library/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/uiComponents/*.cpp"
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(energy_system ${SOURCE_FILES})

target_link_libraries(
    energy_system 
    PRIVATE
    sfml-graphics 
    sfml-window 
    sfml-system 
    TGUI::TGUI
)


if(APPLE)
    target_link_libraries(energy_system PRIVATE "-framework Cocoa" "-framework IOKit" "-framework CoreVideo")
endif()