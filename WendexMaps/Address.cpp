//
// Created by Artem Murashko on 25.04.2021.
//
#include "Address.h"

Address::Address(string address, Coordinates coordinates) {
    this -> address = address;
    this -> coordinates = coordinates;
}

Address::Address() {
    address = "No address name";
    coordinates = Coordinates();
}

string Address::getAddress() {
    return address;
}

Coordinates Address::getCoordinates() {
    return coordinates;
}