//
// Created by Artem Murashko on 10.04.2021.
//

#ifndef WENDEXTAXI_CAR_H
#define WENDEXTAXI_CAR_H

#include <string>
#include <iostream>
#include "CarType.h"
#include "CarColor.h"
#include "../Coordinates.h"

class Car {
protected:
    Car(std::string model, CarType carType, Coordinates currentCoordinates, CarColor color, std::string number);

public:
    std::string getModel();
    CarType getCarType();
    std::string getCarTypeName();
    Coordinates getCurrentCoordinates();
    CarColor getCarColor();
    std::string getCarColorName();
    std::string getNumber();

private:
    std::string model;
    CarType carType;
    Coordinates currentCoordinates = Coordinates();
    CarColor color;
    std::string number;
};


#endif //WENDEXTAXI_CAR_H
