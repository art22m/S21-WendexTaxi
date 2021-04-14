//
// Created by Artem Murashko on 10.04.2021.
//

#ifndef WENDEXTAXI_PASSENGER_H
#define WENDEXTAXI_PASSENGER_H

#include "User.h"
#include "../Gateways/PassengerGateway.h"

class Passenger: public User {
public:
    Passenger(std::string name, double rating);

public:
    PaymentMethods getPaymentMethod();
    void setPaymentMethod(PaymentMethods newPaymentMethod);

private:
    PaymentMethods paymentMethod;
    std::vector <Address> pinnedAddresses;
    friend class PassengerGateway; // give access to all fields of Passenger class for PassengerGateway class
};


#endif //WENDEXTAXI_PASSENGER_H