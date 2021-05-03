//
// Created by Artem Murashko on 27.04.2021.
//
#include "Admin.h"

Admin::Admin(string name, string phoneNumber, string password) {
    this -> name = name;
    this -> password = password;
    this -> phoneNumber = phoneNumber;
}

Admin::Admin() { }

/* Admins Methods */

string Admin::getName() {
    return name;
}

string Admin::getPassword() {
    return password;
}

string Admin::getPhoneNumber() {
    return phoneNumber;
}

void Admin::enter(string password) {
    gateway -> adminEnter(getPhoneNumber(), password);
}

void Admin::exit() {
    gateway -> adminExit(getPhoneNumber());
}

void Admin::registerAccount() {
    gateway -> registerAdmin(this);
}

void Admin::printNumberOfUsers() {
    gateway -> printNumberOfAllUsers(getPhoneNumber());
}

void Admin::validateDriver(string phoneNumber) {
    gateway -> validateDriver(getPhoneNumber(),phoneNumber);
}


void Admin::blockCommand(string phoneNumber, UserFunctions userFunction) {
    gateway -> blockCommand(phoneNumber, userFunction);
}

void Admin::unblockCommand(string phoneNumber, UserFunctions userFunction) {
    gateway -> unblockCommand(phoneNumber, userFunction);
}

/* Drivers Methods */

void Admin::enterDriver(string phoneNumber) {
    gateway -> driverEnter(getPhoneNumber(), phoneNumber);
}

void Admin::exitDriver(string phoneNumber) {
    gateway -> driverExit(getPhoneNumber(), phoneNumber);
}

void Admin::registerDriverAccount(Driver *driver) {
    gateway -> registerDriver(getPhoneNumber(), driver);
}

void Admin::registerCar(string phoneNumber, Car car) {
    gateway -> addCar(getPhoneNumber(), phoneNumber, &car);
}

void Admin::findOrder(string phoneNumber) {
    gateway -> findOrder(getPhoneNumber(), phoneNumber);
}

/* Passengers Methods */

void Admin::enterPassenger(string phoneNumber) {
    gateway -> passengerEnter(getPhoneNumber(), phoneNumber);
}

void Admin::exitPassenger(string phoneNumber) {
    gateway -> passengerExit(getPhoneNumber(), phoneNumber);
}

void Admin::registerPassengerAccount(Passenger *passenger) {
    gateway ->registerPassenger(getPhoneNumber(), passenger);
}

void Admin::makeOrder(string phoneNumber, Address from, Address to, CarType carType) {
    gateway -> makeOrder(getPhoneNumber(), phoneNumber, from, to, carType);
}