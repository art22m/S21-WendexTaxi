//
// Created by Артём Мурашко on 13.04.2021.
//

#ifndef WENDEXTAXI_ADDRESS_H
#define WENDEXTAXI_ADDRESS_H

#include <string>
#include "Coordinates.h"

class Address {
public:
    Address(std::string address, Coordinates coordinates);
    Address();
public:
    std::string getAddress();
    Coordinates getCoordinates();

private:
    std::string address;
    Coordinates coordinates = Coordinates();
};


#endif //WENDEXTAXI_ADDRESS_H
