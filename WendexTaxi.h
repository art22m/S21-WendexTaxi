//
// Created by Artem Murashko on 14.04.2021.
// This file is needed in order to include many files in one line in main.cpp
//

#ifndef WENDEXTAXI_WENDEXTAXI_H
#define WENDEXTAXI_WENDEXTAXI_H

// Include all files from the Cars folder
#include "Cars/Business.h"
#include "Cars/Comfort.h"
#include "Cars/ComfortPlus.h"
#include "Cars/Economy.h"
#include "Cars/Car.h"
#include "Cars/CarType.h"
#include "Cars/CarColor.h"

// Include all files from the Users folder
#include "Users/Driver.h"
#include "Users/Passenger.h"
#include "Users/User.h"

// Include all files from the Gateways folder
#include "Gateways/DriverGateway.h"
#include "Gateways/PassengerGateway.h"

#endif //WENDEXTAXI_WENDEXTAXI_H
