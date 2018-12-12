cmake_minimum_required(VERSION 3.12)
project(simple_example)

set(CMAKE_CXX_STANDARD 14)

add_library(simple_example main.cpp main.h RgbImage.h RgbImage.cpp RgbImage.h RgbImage.cpp)