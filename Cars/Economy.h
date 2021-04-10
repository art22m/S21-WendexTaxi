//
// Created by Artem Murashko on 10.04.2021.
//

#ifndef WENDEXTAXI_ECONOMY_H
#define WENDEXTAXI_ECONOMY_H

#include "Car.h"

class Economy : public Car {
public:
    Economy(std::string model, Coordinates currentCoordinates, CarColor color, std::string number);
};


#endif //WENDEXTAXI_ECONOMY_H
