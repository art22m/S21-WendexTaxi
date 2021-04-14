//
// Created by Artem Murashko on 13.04.2021.
//

#ifndef WENDEXTAXI_DRIVER_H
#define WENDEXTAXI_DRIVER_H

#include "User.h"
#include "../Cars/Car.h"

class Driver : public User {
public:
    Driver(std::string name, double rating, std::string phoneNumber, Car *car);

public:
    bool getBusyStatus();
    void setBusyStatus(bool status);
    Car getCar();

private:
   Car *car;
   bool isBusy;
};

#endif //WENDEXTAXI_DRIVER_H