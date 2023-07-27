cmake_minimum_required(VERSION 3.5)

project(raytracer LANGUAGES CXX VERSION 0.0.1)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra")
include_directories("${PROJECT_SOURCE_DIR}/src")
file(GLOB_RECURSE lib_SOURCES "src/*.cpp")
file(GLOB_RECURSE test_SOURCES "tests/*.cpp")
add_library(src_raytrace ${lib_SOURCES})


find_package(Catch2 REQUIRED)

add_executable(projectile mains/projectile.cpp)
target_link_libraries(projectile src_raytrace)

add_executable(projectileDraw mains/projectileDraw.cpp)
target_link_libraries(projectileDraw src_raytrace)

add_executable(runtests ${test_SOURCES})
target_link_libraries(runtests PUBLIC src_raytrace Catch2::Catch2WithMain)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING
    "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
    FORCE)
endif()


include(CTest)
include(Catch)
catch_discover_tests(runtests)
