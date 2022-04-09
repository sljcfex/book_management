cmake_minimum_required(VERSION 3.21)
project(cw1_shu C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(cw1_shu
        admini.c
        admini.h
        book_management.c
        book_management.h
        interface.c
        interface.h
        main.c
        user.c
        user.h
        userop.c
        userop.h)
