//
// Created by Artem Murashko on 25.04.2021.
//
#include "Passenger.h"

Passenger::Passenger(string name, string phoneNumber, string password, double rating) : User(name, phoneNumber, password, rating) { }
Passenger::Passenger(string name, string phoneNumber, string password) : User(name, phoneNumber, password) { }
Passenger::Passenger() { }

void Passenger::enter(string password) {
    gateway -> passengerEnter(getPhoneNumber(), password);
}

void Passenger::exit() {
    gateway -> passengerExit(getPhoneNumber());
}

void Passenger::registerAccount() {
    gateway -> registerPassenger(this);
}

void Passenger::makeOrder(Address from, Address to, CarType carType) {
    gateway -> makeOrder(getPhoneNumber(), from, to, carType);
}

void Passenger::switchPaymentMethod() {
    if (paymentMethod == PaymentMethods::card)
        paymentMethod = PaymentMethods::cash;
    else
        paymentMethod = PaymentMethods::card;
    cout << "Payment method successfully changed." << endl;
}

string Passenger::getPaymentMethodName() {
    if (paymentMethod == PaymentMethods::card)
        return "card";
    else
        return "cash";
}

void Passenger::printPaymentMethod() {
    cout << "Payment method: ";
    if (paymentMethod == PaymentMethods::card)
        cout << "card" << endl;
    else
        cout << "cash" << endl;
}


