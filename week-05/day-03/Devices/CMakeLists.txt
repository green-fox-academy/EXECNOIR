cmake_minimum_required(VERSION 3.12)
project(Devices)

set(CMAKE_CXX_STANDARD 14)

add_executable(Devices main.cpp Printer.cpp Printer.h Printer3D.cpp Printer3D.h Printer2D.cpp Printer2D.h Scanner.cpp Scanner.h Copier.cpp Copier.h)