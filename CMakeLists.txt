cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)

# Add conjbrew libs. TODO: write this more eloquently
ADD_LIBRARY(ConjbrewLibs
    ./src/utils.cpp
)

add_executable(conjbrew ./src/main.cpp ${DirSOURCES})
target_link_libraries(conjbrew ConjbrewLibs pthread)
