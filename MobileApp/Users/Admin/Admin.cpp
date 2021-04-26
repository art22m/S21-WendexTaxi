//
// Created by Artem Murashko on 27.04.2021.
//
#include "Admin.h"

Admin::Admin(string name, string password, string phoneNumber) {
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

void Admin::enter(string phoneNumber, string password) {
    gateway -> adminEnter(phoneNumber, password);
}

void Admin::registerAccount(Admin *admin) {
    gateway -> registerAdmin(this);
}

void Admin::printNumberOfUsers() {
    gateway -> printNumberOfAllUsers(getPhoneNumber());
}

void Admin::blockCommand(string phoneNumber) {

}

/* Drivers Methods */

void Admin::enterDriver(string phoneNumber) {
    gateway -> driverEnter(phoneNumber);
}

void Admin::exitDriver(string phoneNumber) {
    gateway -> driverExit(phoneNumber);
}

void Admin::registerDriverAccount(Driver *driver) {
    gateway -> registerDriver(driver);
}

void Admin::registerCar(string phoneNumber, Car car) {
    gateway -> addCar(phoneNumber, &car);
}

void Admin::findOrder(string phoneNumber) {
    gateway -> findOrder(phoneNumber);
}

/* Passengers Methods */

void Admin::enterPassenger(string phoneNumber) {
    gateway -> passengerEnter(phoneNumber);
}

void Admin::exitPassenger(string phoneNumber) {
    gateway -> passengerExit(phoneNumber);
}

void Admin::registerPassengerAccount(Passenger *passenger) {
    gateway ->registerPassenger(passenger);
}

void Admin::makeOrder(string phoneNumber, Address from, Address to, CarType carType) {
    gateway -> makeOrder(phoneNumber, from, to, carType);
}