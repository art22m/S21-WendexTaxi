//
// Created by Artem Murashko on 10.04.2021.
//

#ifndef WENDEXTAXI_PASSENGER_H
#define WENDEXTAXI_PASSENGER_H

#include "User.h"

class Passenger: public User {
public:
    Passenger(std::string name, double rating);

public:
    void changePaymentMethod();
    void pinAddress(const Address& address);
    std::vector <Address> getPinnedAddresses();
    void addOrder(const Order& order);
    std::vector <Order> getOrderHistory();

private:
    PaymentMethods paymentMethod;
    std::vector <Address> pinnedAddresses;
    std::vector <Order> orderHistory;
};


#endif //WENDEXTAXI_PASSENGER_H