//
// Created by Artem Murashko on 25.04.2021.
//

#ifndef WENDEXTAXI_CAR_H
#define WENDEXTAXI_CAR_H

#include "CarType.h"
#include "../../WendexMaps.h"
#include <string>

using namespace std;

class Car {
public:
    Car(string model, string color, string licencePlate, CarType carType, Coordinates coordinates);
    Car(string model, string color, string licencePlate, CarType carType);

public:
    string getModel();
    string getColor();
    string getLicencePLate();
    CarType getCarType();
    string getCarTypeName();

private:
    string model;
    string color;
    string licencePlate;
    CarType carType;
    Coordinates coordinates = Coordinates();
};

#endif //WENDEXTAXI_CAR_H
