cmake_minimum_required(VERSION 3.10)
project(cpp)

set(SRC
    src/Exception.cc)

add_library(cpp ${SRC})

target_include_directories(cpp PUBLIC include)
