//
// Created by Artem Murashko on 26.04.2021.
//

#include "PassengerGateway.h"

PassengerGateway::PassengerGateway() { }

void PassengerGateway::passengerEnter(string phoneNumber, string password) {
    if (!Server::request()->isPassengerRegistered(phoneNumber)) {
        cout << "Passenger with such number does not exist!" << endl;
        return;
    }
    if (!Server::request() -> isPassengerPasswordCorrect(phoneNumber, password)) {
        cout << "Incorrect password! Try again." << endl;
        return;
    }

    if (Server::request() ->isPassengerOnline(phoneNumber)) {
        cout << "Passenger already login." << endl;
        return;
    }

    Server::request() -> passengerEnter(phoneNumber);
}

void PassengerGateway::passengerExit(string phoneNumber) {
    if (!Server::request() -> isPassengerOnline(phoneNumber)) {
        cout << "Passenger is not logged in!" << endl;
        return;
    }

    Server::request() -> passengerExit(phoneNumber);
}

void PassengerGateway::registerPassenger(Passenger *passenger) {
    if (Server::request() -> isPassengerRegistered(passenger -> getPhoneNumber())) {
        cout << "Passenger is already registered!" << endl;
        return;
    }
    Server::request() -> registerPassenger(passenger);
}

void PassengerGateway::makeOrder(string phoneNumber, Address from, Address to, CarType carType) {
    if (!Server::request() -> isPassengerOnline(phoneNumber)) {
        cout << "Passenger is not logged in!" << endl;
        return;
    }

    Server::request() -> getOrderInfo(phoneNumber, from, to, carType);
}