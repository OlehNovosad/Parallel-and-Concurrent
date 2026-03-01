cmake_minimum_required(VERSION 3.10.0)
project(thread_pool VERSION 0.1.0 LANGUAGES C CXX)

cmake_policy(SET CMP0167 NEW)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost REQUIRED COMPONENTS thread)

add_executable(thread_pool main.cpp)

target_include_directories(thread_pool PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(thread_pool PRIVATE Boost::thread)
