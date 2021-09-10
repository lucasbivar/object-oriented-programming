cmake_minimum_required(VERSION 3.0.0)
project(Inventory VERSION 0.1.0)

set(CMAKE_BUILD_TYPE Relase)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

add_executable(Inventory src/main.cpp 
                          src/Inventory.cpp src/Tool.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
