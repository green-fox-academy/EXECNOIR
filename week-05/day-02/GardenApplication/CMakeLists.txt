cmake_minimum_required(VERSION 3.12)
project(GardenApplication)

set(CMAKE_CXX_STANDARD 14)

add_executable(GardenApplication main.cpp Flower.cpp Flower.h Garden.cpp Garden.h Tree.cpp Tree.h)