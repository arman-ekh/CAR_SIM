cmake_minimum_required(VERSION 4.1)
project(raylib_test CXX)

set(CMAKE_CXX_STANDARD 20)


set(RAYLIB_INCLUDE_DIR "C:/raylib/w64devkit/include")
set(RAYLIB_LIB_PATH "C:/raylib/w64devkit/lib/libraylib.a")


add_executable(raylib_test main.cpp
        Header/Car.h
        Source/Car.cpp
        Header/Car.h)


target_include_directories(raylib_test PRIVATE ${RAYLIB_INCLUDE_DIR})


target_link_libraries(raylib_test
        ${RAYLIB_LIB_PATH}
        opengl32
        gdi32
        winmm
)