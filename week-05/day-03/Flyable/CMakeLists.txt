cmake_minimum_required(VERSION 3.12)
project(Flyable)

set(CMAKE_CXX_STANDARD 14)

add_executable(Flyable main.cpp Flyable.cpp Flyable.h Vehicle.cpp Vehicle.h Helicopter.cpp Helicopter.h Animal.cpp Animal.h
        Bird.cpp Bird.h Mammal.cpp Mammal.h Reptile.cpp Reptile.h LaysEggs.cpp LaysEggs.h)