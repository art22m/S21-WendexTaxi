//
// Created by Artem Murashko on 14.04.2021.
// This file is needed in order to include many files in one line in main.cpp
//

#ifndef WENDEXTAXI_WENDEXTAXI_H
#define WENDEXTAXI_WENDEXTAXI_H

// Include all files from the MobileApp folder
#include "MobileApp/Users/User.h"
#include "MobileApp/Users/Admin/Admin.h"
#include "MobileApp/Users/Driver/Driver.h"
#include "MobileApp/Users/Passenger/Passenger.h"
#include "MobileApp/Cars/Car.h"
#include "MobileApp/Cars/CarType.h"
#include "MobileApp/Orders/Order.h"

// Include all files from the Gateways folder
#include "Gateways/PassengerGateway/PassengerGateway.h"
#include "Gateways/DriverGateway/DriverGateway.h"
#include "Gateways/AdminGateway/AdminGateway.h"

// Include all files from the Server folder
#include "Server/Server.h"

// Include all files from the DataBase folder
#include "DataBase/DataBase.h"

#endif //WENDEXTAXI_WENDEXTAXI_H