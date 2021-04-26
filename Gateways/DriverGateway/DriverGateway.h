//
// Created by Artem Murashko on 26.04.2021.
//
#ifndef WENDEXTAXI_DRIVERGATEWAY_H
#define WENDEXTAXI_DRIVERGATEWAY_H

#include <string>
#include "../../Server/Server.h"
#include "../../MobileApp/Orders/Order.h"

class Driver;
#include "../../MobileApp/Users/Driver/Driver.h"

using namespace std;

class DriverGateway {
public:
    DriverGateway();

public:
    void driverEnter(string phoneNumber, string password);
    void driverExit(string phoneNumber);
    void registerDriver(Driver *driver);
    void findOrder(string phoneNumber);
    void addCar(string phoneNumber, Car *car);
};


#endif //WENDEXTAXI_DRIVERGATEWAY_H
