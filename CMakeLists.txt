cmake_minimum_required(VERSION 3.19)
project(WendexTaxi)

set(CMAKE_CXX_STANDARD 14)

add_executable(WendexTaxi main.cpp Cars/Car.cpp Cars/Car.h Cars/CarType.h Cars/CarColor.h WendexMaps/Coordinates.h Cars/Economy.cpp Cars/Economy.h Cars/Comfort.cpp Cars/Comfort.h Cars/ComfortPlus.cpp Cars/ComfortPlus.h Cars/Business.cpp Cars/Business.h Users/Passenger.cpp Users/Passenger.h WendexMoney/PaymentMethods.h Users/User.cpp Users/User.h WendexMaps/Address.cpp WendexMaps/Address.h Orders/Order.cpp Orders/Order.h Users/Driver.cpp Users/Driver.h Gateways/PassengerGateway.cpp Gateways/PassengerGateway.h Gateways/DriverGateway.cpp Gateways/DriverGateway.h)