//
// Created by Artem Murashko on 13.04.2021.
//

#ifndef WENDEXTAXI_DRIVER_H
#define WENDEXTAXI_DRIVER_H

#include "User.h"
#include "../Cars/Car.h"
#include "../Gateways/DriverGateway.h"

class Driver : public User {
public:
    Driver(std::string name, double rating, std::string phoneNumber, Car *car);

private:
   Car* car;
   bool isBusy;
   friend class DriverGateway; // give access to all fields of Driver class for DriverGateway class
};


#endif //WENDEXTAXI_DRIVER_H
