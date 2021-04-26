//
// Created by Artem Murashko on 25.04.2021.
//
#ifndef WENDEXTAXI_PASSENGER_H
#define WENDEXTAXI_PASSENGER_H

#include "../User.h"
class PassengerGateway;
#include "../../../Gateways/PassengerGateway/PassengerGateway.h"

class Passenger : public User {
public:
    Passenger(string name, string phoneNumber, string password, double rating);
    Passenger(string name, string phoneNumber, string password);
    Passenger();
public:
    void enter(string password);
    void exit();
    void registerAccount();
    void makeOrder(Address from, Address to, CarType carType);
private:
    PassengerGateway *gateway;
};


#endif //WENDEXTAXI_PASSENGER_H
