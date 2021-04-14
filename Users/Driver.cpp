//
// Created by Artem Murashko on 13.04.2021.
//

#include "Driver.h"

Driver::Driver(std::string name, double rating, Car *car) : User(name, rating) {
    this -> car = car;
    isBusy = false;
}