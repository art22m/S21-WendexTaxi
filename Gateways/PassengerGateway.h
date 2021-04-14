//
// Created by Artem Murashko on 14.04.2021.
//

#ifndef WENDEXTAXI_PASSENGERGATEWAY_H
#define WENDEXTAXI_PASSENGERGATEWAY_H

#include "../Users/User.h"
#include "../Cars/CarType.h"
#include "../Service/System.h"
#include <vector>

class Passenger;

class PassengerGateway {
public:
    PassengerGateway();

public:
    void seeOrderHistory(Passenger &passenger);
    void seePinnedAddresses(Passenger &passenger);
    void createOrder(Passenger &passenger, Address from, Address to, CarType type);
    void askCurrentCoordinates(Passenger &passenger);
    void askBill(Passenger &passenger);

    std::vector<Order> getOrderHistory(Passenger &passenger);
    void changePaymentMethod(Passenger &passenger);
    void pinAddress(Passenger &passenger, Address address);
    std::vector <Address> getPinnedAddresses(Passenger &passenger);
};

#endif //WENDEXTAXI_PASSENGERGATEWAY_H