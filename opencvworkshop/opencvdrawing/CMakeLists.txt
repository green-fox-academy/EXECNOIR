cmake_minimum_required(VERSION 3.12)
project(ocv_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Where to find CMake modules and OpenCV
set(OpenCV_DIR "C:\\opencv4.0.1\\mingw-build-contrib\\install\\x64\\mingw\\lib")
set(SQLITE3_DIR "C:\\sqlite\\sqlite3\\lib\\cmake")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(OpenCV REQUIRED)
find_package(SQLITE3)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("C:/sqlite/sqlite3/include/sqlite3")


add_executable(ocv_test main.cpp)

# add libs you need


# linking
target_link_libraries(ocv_test ${OpenCV_LIBS} sqlite3::sqlite3)