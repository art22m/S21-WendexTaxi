//
// Created by Artem Murashko on 13.04.2021.
//

#include "Driver.h"

Driver::Driver(std::string name, double rating, std::string phoneNumber, Car *car) : User(name, rating, phoneNumber) {
    this -> car = car;
    this -> isBusy = false;
}

bool Driver::getBusyStatus() {
    return isBusy;
}

void Driver::setBusyStatus(bool status) {
    isBusy = status;
}

Car Driver::getCar() {
    return *car;
}
