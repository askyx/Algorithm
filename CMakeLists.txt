cmake_minimum_required(VERSION 3.0.0)
project(Algorithm VERSION 0.1.0)

# CMAKE_CXX_STANDARD()
set(CMAKE_CXX_STANDARD 20)
include(CTest)
enable_testing()

add_executable(Algorithm main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
