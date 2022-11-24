cmake_minimum_required(VERSION 3.23)
project(Trees)

set(CMAKE_CXX_STANDARD 98)

add_executable(Trees main.cpp Static/CNodeStatic.cpp Static/CNodeStatic.h Dynamic/CNodeDynamic.cpp Dynamic/CNodeDynamic.h)
