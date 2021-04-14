//
// Created by Artem Murashko on 13.04.2021.
//

#include "Driver.h"

Driver::Driver(std::string name, double rating, std::string phoneNumber, Car *car) : User(name, rating, phoneNumber) {
    this -> car = car;
    isBusy = false;
}