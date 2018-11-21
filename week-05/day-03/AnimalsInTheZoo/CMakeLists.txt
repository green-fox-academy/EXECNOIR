cmake_minimum_required(VERSION 3.12)
project(AnimalsInTheZoo)

set(CMAKE_CXX_STANDARD 14)

add_executable(AnimalsInTheZoo main.cpp Animal.cpp Animal.h Mammal.cpp Mammal.h Reptile.cpp Reptile.h Bird.cpp Bird.h LaysEggs.cpp LaysEggs.h)