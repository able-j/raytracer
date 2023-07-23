cmake_minimum_required(VERSION 3.5)

project(raytracer LANGUAGES CXX VERSION 0.0.1)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra")
include_directories("${PROJECT_SOURCE_DIR}/src")
file(GLOB_RECURSE lib_SOURCES "src/*.cpp")
file(GLOB_RECURSE test_SOURCES "tests/*.cpp")
add_library(src_library SHARED ${lib_SOURCES})
install(TARGETS src_library DESTINATION lib)

find_package(Catch2 REQUIRED)

add_executable(runtests ${test_SOURCES})
target_link_libraries(runtests PRIVATE src_library Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(runtests)
