cmake_minimum_required(VERSION 3.19)
project(WendexTaxi)

set(CMAKE_CXX_STANDARD 14)

add_executable( WendexTaxi main.cpp
                WendexTaxi.h MobileApp/Users/User.cpp
                MobileApp/Users/User.h
                MobileApp/Users/Driver/Driver.cpp
                MobileApp/Users/Driver/Driver.h
                MobileApp/Users/Passenger/Passenger.cpp
                MobileApp/Users/Passenger/Passenger.h
                MobileApp/Cars/Car.cpp
                MobileApp/Cars/Car.h
                MobileApp/Cars/CarType.h
                WendexMaps/Coordinates.h
                Server/Server.cpp
                Server/Server.h
                MobileApp/Orders/Order.cpp
                MobileApp/Orders/Order.h
                WendexMaps/Address.cpp
                WendexMaps/Address.h
                WendexMaps.h
                DataBase/DataBase.cpp
                DataBase/DataBase.h
                Gateways/PassengerGateway/PassengerGateway.cpp
                Gateways/PassengerGateway/PassengerGateway.h
                Gateways/DriverGateway/DriverGateway.cpp
                Gateways/DriverGateway/DriverGateway.h MobileApp/Orders/PaymentMethods.h Gateways/AdminGateway/AdminGateway.cpp Gateways/AdminGateway/AdminGateway.h MobileApp/Users/Admin/Admin.cpp MobileApp/Users/Admin/Admin.h)