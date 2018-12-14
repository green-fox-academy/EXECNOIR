cmake_minimum_required(VERSION 3.12)
project(linked_list_try C)

set(CMAKE_C_STANDARD 99)

add_executable(linked_list_try main.c linked_list.c linked_list.h)