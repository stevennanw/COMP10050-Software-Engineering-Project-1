cmake_minimum_required(VERSION 3.16)
project(assignment3 C)

set(CMAKE_C_STANDARD 11)

find_library(CUNIT libcunit.a /usr/local/Cellar/cunit/2.1-3/lib)
include_directories(/usr/local/Cellar/cunit/2.1-3/include/CUnit .)

add_executable(assignment3 main.c avg_and_max.c avg_and_max.h)

target_link_libraries(assignment3 PUBLIC ${CUNIT})