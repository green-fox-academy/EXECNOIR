cmake_minimum_required(VERSION 3.12)
project(FleetOfThings)

set(CMAKE_CXX_STANDARD 14)

add_executable(FleetOfThings main.cpp Thing.cpp Thing.h Fleet.cpp Fleet.h)