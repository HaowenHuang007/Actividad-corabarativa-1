cmake_minimum_required(VERSION 4.3)
project(Primera_actividad_colaborativa)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Primera_actividad_colaborativa
        libro.cpp
        main.cpp
        libro.h
)
