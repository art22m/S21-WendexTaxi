//
// Created by Artem Murashko on 27.04.2021.
//
#include "AdminGateway.h"

/* -- Constructor -- */

AdminGateway::AdminGateway() { };

/* ---> Drivers Methods <--- */

// Admin don't need to know password os driver
void AdminGateway::driverEnter(string adminPhoneNumber, string phoneNumber) {
    if (!Server::request() -> isAdminOnline(adminPhoneNumber)) {
        cout << "Admin is not logged in!" << endl;
        return;
    }

    if (!Server::request() -> isDriverRegistered(phoneNumber)) {
        cout << "Driver with such number does not exist!" << endl;
        return;
    }

    Server::request() -> driverEnter(phoneNumber);
}

void AdminGateway::driverExit(string adminPhoneNumber, string phoneNumber) {
    if (!Server::request() -> isAdminOnline(adminPhoneNumber)) {
        cout << "Admin is not logged in!" << endl;
        return;
    }

    if (!Server::request() -> isDriverOnline(phoneNumber)) {
        cout << "Driver is not logged in!" << endl;
        return;
    }

    Server::request() -> driverExit(phoneNumber);
}

void AdminGateway::registerDriver(string adminPhoneNumber, Driver *driver) {
    if (!Server::request() -> isAdminOnline(adminPhoneNumber)) {
        cout << "Admin is not logged in!" << endl;
        return;
    }

    if (Server::request() -> isDriverRegistered(driver -> getPhoneNumber())) {
        cout << "Driver is already registered!" << endl;
        return;
    }

    Server::request() -> registerDriver(driver);
}

void AdminGateway::findOrder(string adminPhoneNumber, string phoneNumber) {
    if (!Server::request() -> isAdminOnline(adminPhoneNumber)) {
        cout << "Admin is not logged in!" << endl;
        return;
    }

    if (!Server::request() -> isDriverOnline(phoneNumber)) {
        cout << "Driver is not logged in!" << endl;
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

void AdminGateway::addCar(string adminPhoneNumber, string phoneNumber, Car *car) {
    if (!Server::request() -> isAdminOnline(adminPhoneNumber)) {
        cout << "Admin is not logged in!" << endl;
        return;
    }

    if (!Server::request() -> isDriverOnline(phoneNumber)) {
        cout << "Driver is not logged in!" << endl;
        return;
    }

    Server::request() -> addCar(phoneNumber, car);
}

/* ---> Passengers Methods <--- */

// Admin don't need to know password of passenger
void AdminGateway::passengerEnter(string adminPhoneNumber, string phoneNumber) {
    if (!Server::request() -> isAdminOnline(adminPhoneNumber)) {
        cout << "Admin is not logged in!" << endl;
        return;
    }

    if (!Server::request()->isPassengerRegistered(phoneNumber)) {
        cout << "Passenger with such number does not exist!" << endl;
        return;
    }

    Server::request() -> passengerEnter(phoneNumber);
}

void AdminGateway::passengerExit(string adminPhoneNumber, string phoneNumber) {
    if (!Server::request() -> isAdminOnline(adminPhoneNumber)) {
        cout << "Admin is not logged in!" << endl;
        return;
    }

    if (!Server::request() -> isPassengerOnline(phoneNumber)) {
        cout << "Passenger is not logged in!" << endl;
        return;
    }

    Server::request() -> passengerExit(phoneNumber);
}

void AdminGateway::registerPassenger(string adminPhoneNumber, Passenger *passenger) {
    if (!Server::request() -> isAdminOnline(adminPhoneNumber)) {
        cout << "Admin is not logged in!" << endl;
        return;
    }

    if (Server::request() -> isPassengerRegistered(passenger -> getPhoneNumber())) {
        cout << "Passenger is already registered!" << endl;
        return;
    }
    Server::request() -> registerPassenger(passenger);
}

void AdminGateway::makeOrder(string adminPhoneNumber, string phoneNumber, Address from, Address to, CarType carType) {
    if (!Server::request() -> isAdminOnline(adminPhoneNumber)) {
        cout << "Admin is not logged in!" << endl;
        return;
    }

    if (!Server::request() -> isPassengerOnline(phoneNumber)) {
        cout << "Passenger is not logged in!" << endl;
        return;
    }

    Server::request() -> getOrderInfo(phoneNumber, from, to, carType);
}

/* ---> Admins Methods <--- */

void AdminGateway::adminEnter(string phoneNumber, string password) {
    if (!Server::request() -> isAdminRegistered(phoneNumber)) {
        cout << "Admin with such number does not exist!" << endl;
        return;
    }

    if (!Server::request() -> isAdminPasswordCorrect(phoneNumber, password)) {
        cout << "Incorrect password! Try again." << endl;
        return;
    }

    if (Server::request() -> isAdminOnline(phoneNumber)) {
        cout << "Admin is already login!" << endl;
        return;
    }


    Server::request() -> adminEnter(phoneNumber);
}

void AdminGateway::blockCommand(string phoneNumber, UserFunctions userFunction) {
    Server::request() -> blockCommand(phoneNumber, userFunction);
}

void AdminGateway::unblockCommand(string phoneNumber, UserFunctions userFunction) {
    Server::request() -> unblockCommand(phoneNumber, userFunction);
}

void AdminGateway::adminExit(string phoneNumber) {
    if (!Server::request() -> isAdminOnline(phoneNumber)) {
        cout << "Admin is not logged in!" << endl;
        return;
    }

    Server::request() -> adminExit(phoneNumber);
}

void AdminGateway::validateDriver(string adminPhoneNumber, string phoneNumber) {
    if (!Server::request() -> isAdminOnline(adminPhoneNumber)) {
        cout << "Admin is not logged in!" << endl;
        return;
    }

    Server::request() -> validateDriver(phoneNumber);
}

void AdminGateway::registerAdmin(Admin *admin) {
    if (Server::request() -> isAdminRegistered(admin -> getPhoneNumber())) {
        cout << "Admin is already registered!" << endl;
        return;
    }

    Server::request() -> registerAdmin(admin);
}

void AdminGateway::printNumberOfAllUsers(string phoneNumber) {
    if (!Server::request() -> isAdminOnline(phoneNumber)) {
        cout << "Admin is not logged in!" << endl;
        return;
    }

    Server::request() -> printDataBaseStatistics();
}
