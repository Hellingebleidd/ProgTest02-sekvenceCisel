cmake_minimum_required(VERSION 3.12)
project(ProgTest02_sekvenceCisel C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -pedantic")

add_executable(ProgTest02_sekvenceCisel main.c)
