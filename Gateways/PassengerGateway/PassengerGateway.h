//
// Created by Artem Murashko on 26.04.2021.
//
#ifndef WENDEXTAXI_PASSENGERGATEWAY_H
#define WENDEXTAXI_PASSENGERGATEWAY_H

#include <string>
#include "../../Server/Server.h"
#include "../../MobileApp/Orders/Order.h"

class Passenger;
#include "../../MobileApp/Users/Passenger/Passenger.h"

using namespace std;

class PassengerGateway {
public:
    PassengerGateway();
public:
    void passengerEnter(string phoneNumber, string password);
    void passengerExit(string phoneNumber);
    void registerPassenger(Passenger *passenger);
    void makeOrder(string phoneNumber, Address from, Address to, CarType carType);
};

#endif //WENDEXTAXI_PASSENGERGATEWAY_H
