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
    void driverEnter(string adminPhoneNumber, string phoneNumber);
    void driverExit(string adminPhoneNumber, string phoneNumber);
    void registerDriver(string adminPhoneNumber, Driver *driver);
    void findOrder(string adminPhoneNumber, string phoneNumber);
    void addCar(string adminPhoneNumber, string phoneNumber, Car *car);

    /* ---> All passengers Methods <--- */
    void passengerEnter(string adminPhoneNumber, string phoneNumber);
    void passengerExit(string adminPhoneNumber, string phoneNumber);
    void registerPassenger(string adminPhoneNumber, Passenger *passenger);
    void makeOrder(string adminPhoneNumber, string phoneNumber, Address from, Address to, CarType carType);

    /* ---> Admins Methods <--- */
    void adminEnter(string phoneNumber, string password);
    void adminExit(string phoneNumber);
    void registerAdmin(Admin *admin);
    void printNumberOfAllUsers(string phoneNumber);
    void validateDriver(string adminPhoneNumber, string phoneNumber);
    void blockCommand(string phoneNumber, UserFunctions userFunction);
    void unblockCommand(string phoneNumber, UserFunctions userFunction);
};

#endif //WENDEXTAXI_ADMINGATEWAY_H