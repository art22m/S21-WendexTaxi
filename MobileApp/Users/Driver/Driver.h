//
// Created by Artem Murashko on 25.04.2021.
//
#ifndef WENDEXTAXI_DRIVER_H
#define WENDEXTAXI_DRIVER_H

#include "../User.h"

class Driver : public User {
public:
    Driver(string name, string phoneNumber, string password, double rating);
    Driver();
private:
    vector <Car> cars;
    int numberOfRides;
};


#endif //WENDEXTAXI_DRIVER_H
