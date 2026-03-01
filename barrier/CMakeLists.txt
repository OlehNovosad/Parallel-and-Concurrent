cmake_minimum_required(VERSION 3.10.0)
project(barrier VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost REQUIRED COMPONENTS thread)

add_executable(barrier main.cpp)

target_include_directories(barrier PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(barrier PRIVATE Boost::thread)

