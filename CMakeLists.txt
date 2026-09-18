cmake_minimum_required(VERSION 4.3)
project(MotionLabEngine)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCE src/*.cpp)
file(GLOB IM_GUI_SOURCE dependencies/ImGUI/*.cpp)
set(IM_GUI_BACKENDS_SOURCES
        dependencies/ImGUI/backends/imgui_impl_glfw.cpp
        dependencies/ImGUI/backends/imgui_impl_opengl3.cpp
)

set(LINK_LIBS)

if (MINGW) # Windows MinGW TODO: SUPPORT MSVC
    list(APPEND LINK_LIBS opengl32 ${CMAKE_SOURCE_DIR}/dependencies/mingw-w64/GLFW/libglfw3.a)
else (MINGW) # Linux & Mac (not tested on MacOS, although it SHOULD work)
    find_package(OpenGL REQUIRED)
    list(APPEND LINK_LIBS OpenGL::GL)
    if (APPLE)
        list(APPEND LINK_LIBS ${CMAKE_SOURCE_DIR}/dependencies/macos/GLFW/libglfw3.a)
    else (APPLE)
        find_package(glfw3 3.5 REQUIRED)
        list(APPEND LINK_LIBS glfw)
    endif (APPLE)
endif (MINGW)

add_library(MotionLabEngine SHARED ${SOURCE} ${IM_GUI_SOURCE} ${IM_GUI_BACKENDS_SOURCES} dependencies/GLAD/src/glad.c)
include_directories(include dependencies/GLFW/include dependencies/GLAD/include dependencies/ImGUI dependencies/ImGUI/backends)
target_link_libraries(MotionLabEngine ${LINK_LIBS})  # TODO: use some sort of a variable to automatically get the correct compiler folder

file(GLOB TEST_SOURCE test/src/*.cpp)

add_executable(MotionLabTest ${TEST_SOURCE})
include_directories(.)
target_link_libraries(MotionLabTest PRIVATE MotionLabEngine)