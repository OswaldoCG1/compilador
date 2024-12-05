cmake_minimum_required(VERSION 3.29)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        recorrer_arch.cpp
        recorrer_arch.h
        automataNumReal.cpp
        automataNumReal.h
        automataNumEntero.cpp
        automataNumEntero.h
        automataID.cpp
        automataID.h)
