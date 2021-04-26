//
// Created by Artem Murashko on 25.04.2021.
//

#ifndef WENDEXTAXI_SERVER_H
#define WENDEXTAXI_SERVER_H

#include "../DataBase/DataBase.h"

#include "../MobileApp/Users/Driver/Driver.h"
#include "../MobileApp/Orders/Order.h"

class Passenger;
#include "../MobileApp/Users/Passenger/Passenger.h"

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
    void findOrder(string phoneNumber);
    void registerDriver(Driver driver);
    bool isDriverRegistered(string phoneNumber);
    bool isDriverOnline(string phoneNumber);
    bool isDriverPasswordCorrect(string number, string password);

    /*-----> Passenger Methods <-----*/
    void passengerEnter(string phoneNumber);
    void passengerExit(string phoneNumber);
    void registerPassenger(Passenger *passenger);
    void addOrder(string phoneNumber, Order order);
    void getOrderInfo(string phoneNumber, Address from, Address to, CarType carType);
    bool isPassengerRegistered(string phoneNumber);
    bool isPassengerOnline(string phoneNumber);
    bool isPassengerPasswordCorrect(string number, string password);

private:
    map <string, bool> onlinePassengers; // Map where key -> phone number and value -> bool value (false - not online and vise versa)
    map <string, bool> onlineDrivers; // Map where key -> phone number and value -> pointer to the driver
    vector <Order> activeOrders;

    Server();
};


#endif //WENDEXTAXI_SERVER_H
