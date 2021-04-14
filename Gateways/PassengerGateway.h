//
// Created by Artem Murashko on 14.04.2021.
//

#ifndef WENDEXTAXI_PASSENGERGATEWAY_H
#define WENDEXTAXI_PASSENGERGATEWAY_H

#include "../Users/User.h"
#include "../Cars/CarType.h"
#include <vector>

class Passenger;

class PassengerGateway {
public:
    PassengerGateway();

public:
    std::vector<Order> getOrderHistory(Passenger &passenger);
    void createOrder(Passenger &passenger, Address from, Address to, CarType type);
    void changePaymentMethod(Passenger &passenger);
    void pinAddress(Passenger &passenger, Address address);
    std::vector <Address> getPinnedAddresses(Passenger &passenger);
};


#endif //WENDEXTAXI_PASSENGERGATEWAY_H
