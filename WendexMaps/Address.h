//
// Created by Artem Murashko on 25.04.2021.
//
#ifndef WENDEXTAXI_ADDRESS_H
#define WENDEXTAXI_ADDRESS_H

#include "Coordinates.h"
#include <string>

using namespace std;

class Address {
public:
    Address(string address, Coordinates coordinates);
    Address();

    string getAddress();
    Coordinates getCoordinates();

private:
    string address;
    Coordinates coordinates = Coordinates();
};


#endif //WENDEXTAXI_ADDRESS_H
