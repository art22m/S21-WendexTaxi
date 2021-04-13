//
// Created by Artem Murashko on 13.04.2021.
//

#include "Address.h"

Address::Address(std::string address, Coordinates coordinates) {
    this -> address = address;
    this -> coordinates = coordinates;
}

Address::Address() {
    this -> address = "";
    this -> coordinates = Coordinates();
}

std::string Address::getAddress() {
    return address;
}

Coordinates Address::getCoordinates() {
    return coordinates;
}
