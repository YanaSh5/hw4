cmake_minimum_required(VERSION 3.7)
project(HW4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES testEnigma.cpp Enigma.cpp list.h)
add_executable(HW4 ${SOURCE_FILES})