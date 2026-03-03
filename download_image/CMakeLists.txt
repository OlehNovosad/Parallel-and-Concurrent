cmake_minimum_required(VERSION 4.1)
project(download_image)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED COMPONENTS thread)
find_package(CURL REQUIRED)

add_executable(download_image main.cpp)

target_link_libraries(download_image Boost::thread CURL::libcurl)
