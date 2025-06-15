cmake_minimum_required(VERSION 3.24)
project(lru C)

set(CMAKE_C_STANDARD 11)

# Enable ASan
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -g")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")

set(SOURCES
        main.c
        hash.c
        chain.c
        node.c
        lru.cpp lru.h)

add_executable(lru
        ${SOURCES})
