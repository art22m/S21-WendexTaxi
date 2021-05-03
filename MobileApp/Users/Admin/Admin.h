//
// Created by Artem Murashko on 27.04.2021.
//

#ifndef WENDEXTAXI_ADMIN_H
#define WENDEXTAXI_ADMIN_H

#include <string>
#include "../UserFunctions.h"

class AdminGateway;
#include "../../../Gateways/AdminGateway/AdminGateway.h"
using namespace std;

class Admin {
public:
    Admin(string name, string phoneNumber, string password);
    Admin();

// Getters
public:
    string getName();
    string getPassword();
    string getPhoneNumber();

public:
    /* Admins Methods */
    void enter(string password);
    void exit();
    void registerAccount();
    void printNumberOfUsers();
    void validateDriver(string phoneNumber);
    void blockCommand(string phoneNumber, UserFunctions userFunction);
    void unblockCommand(string phoneNumber, UserFunctions userFunction);

    /* Drivers Methods */
    void enterDriver(string phoneNumber);
    void exitDriver(string phoneNumber);
    void registerDriverAccount(Driver *driver);
    void registerCar(string phoneNumber, Car car); // Registers a car with a request to the server
    void findOrder(string phoneNumber);

    /* Passengers Methods */
    void enterPassenger(string phoneNumber);
    void exitPassenger(string phoneNumber);
    void registerPassengerAccount(Passenger *passenger);
    void makeOrder(string phoneNumber, Address from, Address to, CarType carType);

private:
    string name;
    string password;
    string phoneNumber;

private:
    AdminGateway *gateway;
};

#endif //WENDEXTAXI_ADMIN_H