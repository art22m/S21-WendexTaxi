//
// Created by Artem Murashko on 25.04.2021.
//

#ifndef WENDEXTAXI_SERVER_H
#define WENDEXTAXI_SERVER_H

#include "../DataBase/DataBase.h"
#include "../MobileApp/Orders/Order.h"
#include "../MobileApp/Users/UserFunctions.h"

class Driver;
#include "../MobileApp/Users/Driver/Driver.h"

class Passenger;
#include "../MobileApp/Users/Passenger/Passenger.h"

class Admin;
#include "../MobileApp/Users/Admin/Admin.h"

#include <vector>
#include <map>

/*-- Singleton class Server --*/
class Server {
public:
    static Server* request() {
        static Server instance;
        return &instance;
    }
public:
    /*-----> Driver Methods <-----*/
    void driverEnter(string phoneNumber);
    void driverExit(string phoneNumber);
    void registerDriver(Driver *driver);
    void findOrder(string phoneNumber);
    void addCar(string phoneNumber, Car *car);
    Car* getCurrentCar(string phoneNumber);
    bool isDriverRegistered(string phoneNumber);
    bool isDriverOnline(string phoneNumber);
    bool isDriverPasswordCorrect(string number, string password);
    bool isDriverHasCars(string phoneNumber);
    bool isDriverValidated(string phoneNumber);

    /*-----> Passenger Methods <-----*/
    void passengerEnter(string phoneNumber);
    void passengerExit(string phoneNumber);
    void registerPassenger(Passenger *passenger);
    void addOrder(string phoneNumber, Order order);
    void getOrderInfo(string phoneNumber, Address from, Address to, CarType carType);
    bool isPassengerRegistered(string phoneNumber);
    bool isPassengerOnline(string phoneNumber);
    bool isPassengerPasswordCorrect(string phoneNumber, string password);

    /* ---> Admins Methods <--- */
    void adminEnter(string phoneNumber);
    void adminExit(string phoneNumber);
    void validateDriver(string phoneNumber);
    void blockCommand(string phoneNumber, UserFunctions userFunction);
    void unblockCommand(string phoneNumber, UserFunctions userFunction);
    void printDataBaseStatistics();
    void registerAdmin(Admin *admin);
    bool isAdminPasswordCorrect(string phoneNumber, string password);
    bool isAdminRegistered(string phoneNumber);
    bool isAdminOnline(string phoneNumber);

    bool isBlocked(string phoneNumber, UserFunctions userFunction);

private:
    map <string, bool> onlinePassengers; // Map where key -> phone number and value -> bool value (false - not online and vise versa)
    map <string, bool> onlineDrivers; // Map where key -> phone number and value -> bool value
    map <string, bool> onlineAdmins; // Map where key -> phone number and value -> bool value
    map <string, vector<UserFunctions>> blockedCommands; // Map where key -> phone number and value -> commands which blocked for the user
    vector <Order> activeOrders;

    Server();
};


#endif //WENDEXTAXI_SERVER_H
