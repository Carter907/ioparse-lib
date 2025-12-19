cmake_minimum_required(VERSION 3.28)

project(ioparselib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address --pedantic")

add_library(ioparse STATIC src/parse.cpp src/prompt.cpp)

# 2. Define include paths
target_include_directories(ioparse
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# find_package(Catch2 3 REQUIRED) # unit testing library

# add_executable(app src/main.cpp src/parse.cpp src/prompt.cpp)


# These tests can use the Catch2-provided main
# add_executable(tests test.cpp)
# target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
# target_include_directories(tests PRIVATE src)
