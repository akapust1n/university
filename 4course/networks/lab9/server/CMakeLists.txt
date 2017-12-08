cmake_minimum_required(VERSION 3.8)
project(server)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        client.c
        client.h
        cyclobuffer.c
        cyclobuffer.h
        logger.c
        logger.h
        main.c
        structs.h)

add_executable(server ${SOURCE_FILES})