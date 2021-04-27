//
// Created by Artem Murashko on 26.04.2021.
//
#include "DriverGateway.h"

DriverGateway::DriverGateway() { }

void DriverGateway::driverEnter(string phoneNumber, string password) {
    if (!Server::request() -> isDriverRegistered(phoneNumber)) {
        cout << "Driver with such number does not exist!" << endl;
        return;
    }
    if (!Server::request() -> isDriverPasswordCorrect(phoneNumber, password)) {
        cout << "Incorrect password! Try again." << endl;
        return;
    }

    if (Server::request() -> isDriverOnline(phoneNumber)) {
        cout << "Driver already login." << endl;
        return;
    }

    Server::request() -> driverEnter(phoneNumber);
}

void DriverGateway::driverExit(string phoneNumber) {
    if (!Server::request() -> isDriverOnline(phoneNumber)) {
        cout << "Driver is not logged in!" << endl;
        return;
    }

    Server::request() ->driverExit(phoneNumber);
}

void DriverGateway::registerDriver(Driver *driver) {
    if (Server::request() -> isDriverRegistered(driver -> getPhoneNumber())) {
        cout << "Driver is already registered!" << endl;
        return;
    }

    Server::request() -> registerDriver(driver);
}

void DriverGateway::findOrder(string phoneNumber) {
    if (!Server::request() -> isDriverOnline(phoneNumber)) {
        cout << "Driver is not logged in!" << endl;
        return;
    }

    if(!Server::request() -> isDriverValidated(phoneNumber)) {
        cout << "Your driver account is not validated. Please, write to support." << endl;
        return;
    }

    if (!Server::request() -> isDriverHasCars(phoneNumber)) {
        cout << "Driver has no cars!" << endl;
        cout << "Please, register a car!" << endl;
        return;
    }

    if (Server::request() -> getCurrentCar(phoneNumber) == nullptr) {
        cout << "Please, choose current car!" << endl;
        return;
    }

    Server::request() -> findOrder(phoneNumber);
}

void DriverGateway::addCar(string phoneNumber, Car *car) {
    if (!Server::request() -> isDriverOnline(phoneNumber)) {
        cout << "Driver is not logged in!" << endl;
        return;
    }

    Server::request() -> addCar(phoneNumber, car);
}
