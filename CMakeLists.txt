cmake_minimum_required(VERSION 3.24)
project(lru C)

set(CMAKE_C_STANDARD 11)

set(SOURCES
        main.c
        hash.c
        chain.c
        node.c
        )

add_executable(lru
        ${SOURCES})
