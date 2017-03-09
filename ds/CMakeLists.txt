project(ds)
cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "C++11 support has been enabled by default.")

file(GLOB INC ${CMAKE_CURRENT_LIST_DIR}/include/*.h)
file(GLOB SRC ${CMAKE_CURRENT_LIST_DIR}/src/*.cc)
file(GLOB TEST ${CMAKE_CURRENT_LIST_DIR}/tests/*.cc)

source_group(include FILES ${INC})
source_group(src FILES ${SRC})
source_group(tests FILES ${TEST})

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
add_executable(ds ${INC} ${SRC} ${TEST})
