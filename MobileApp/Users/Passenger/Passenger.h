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

    void switchPaymentMethod(); // change payment method from 'cash' to 'card' and vise versa
    string getPaymentMethodName(); // return a string name of payment method
    void printPaymentMethod(); // just print into console the payment method

    void pinAddress(Address address);
    vector <Address> getPinnedAddresses();
    void printPinnedAddresses();

    void askBillForLastRide();

private:
    PassengerGateway *gateway;
    PaymentMethods paymentMethod = PaymentMethods::card;
    vector <Address> pinnedAddresses;
};


#endif //WENDEXTAXI_PASSENGER_H
