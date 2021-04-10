cmake_minimum_required(VERSION 3.19)
project(WendexTaxi)

set(CMAKE_CXX_STANDARD 14)

add_executable(WendexTaxi main.cpp Cars/Car.cpp Cars/Car.h Cars/CarType.h Cars/CarColor.h Coordinates.h Cars/Economy.cpp Cars/Economy.h Cars/Comfort.cpp Cars/Comfort.h Cars/ComfortPlus.cpp Cars/ComfortPlus.h Cars/Business.cpp Cars/Business.h)