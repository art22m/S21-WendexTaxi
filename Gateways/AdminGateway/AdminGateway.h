//
// Created by Artem Murashko on 27.04.2021.
//
#ifndef WENDEXTAXI_ADMINGATEWAY_H
#define WENDEXTAXI_ADMINGATEWAY_H

#include <string>
#include "../../Server/Server.h"
#include "../../MobileApp/Orders/Order.h"

class Driver;
#include "../../MobileApp/Users/Driver/Driver.h"
class Passenger;
#include "../../MobileApp/Users/Passenger/Passenger.h"

class AdminGateway {
public:
    AdminGateway();

public:
    /* ---> All rivers Methods <--- */
    void driverEnter(string phoneNumber);
    void driverExit(string phoneNumber);
    void registerDriver(Driver *driver);
    void findOrder(string phoneNumber);
    void addCar(string phoneNumber, Car *car);

    /* ---> All passengers Methods <--- */
    void passengerEnter(string phoneNumber);
    void passengerExit(string phoneNumber);
    void registerPassenger(Passenger *passenger);
    void makeOrder(string phoneNumber, Address from, Address to, CarType carType);

    /* ---> Admins Methods <--- */
    void adminEnter(string phoneNumber, string password);
    void adminExit(string phoneNumber);
    void registerAdmin(Admin *admin);
    void printNumberOfAllUsers(string phoneNumber);
    void blockCommand(string phoneNumber);
};

#endif //WENDEXTAXI_ADMINGATEWAY_H
