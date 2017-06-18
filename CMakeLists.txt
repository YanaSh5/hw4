cmake_minimum_required(VERSION 3.7)
project(hw4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES EscapeRoomWrapper.cpp EscaperRoom.c EscapeRoom.h)
add_executable(hw4 ${SOURCE_FILES})