cmake_minimum_required(VERSION 3.27)
project(progect)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(progect
        src/functions.h
        src/functions.cpp
        src/main.cpp
        src/structs.h
        src/structs.cpp
        src/accountSystemManager.cpp
        src/accountSystemManager.h
)
