cmake_minimum_required(VERSION 3.7)
project(TestC)


set(CMAKE_CXX_STANDARD 11)

add_executable(TestC src/main.cpp src/file/CFile.cpp src/file/CFile.h src/stl/CString.cpp src/stl/CString.h)