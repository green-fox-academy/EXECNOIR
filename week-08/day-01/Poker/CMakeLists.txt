cmake_minimum_required(VERSION 3.12)
project(Poker)

set(CMAKE_CXX_STANDARD 14)

add_executable(Poker_run main.cpp)

include_directories(Cards)
add_subdirectory(Cards)
add_subdirectory(PokerTest)

target_link_libraries(Poker_run Cards)