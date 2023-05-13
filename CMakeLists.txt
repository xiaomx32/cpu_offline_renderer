cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Debug)
endif()

project(weekend LANGUAGES CXX)

add_subdirectory(src/basic)
add_subdirectory(src/raytracing)

add_executable(main src/main.cpp)

target_link_libraries(main PUBLIC basic)
target_link_libraries(main PUBLIC raytracing)
