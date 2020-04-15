cmake_minimum_required(VERSION 3.5)

project(libmimes)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(test-app)
