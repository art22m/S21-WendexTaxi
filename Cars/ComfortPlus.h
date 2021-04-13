//
// Created by Artem Murashko on 10.04.2021.
//

#ifndef WENDEXTAXI_COMFORTPLUS_H
#define WENDEXTAXI_COMFORTPLUS_H

#include "Car.h"

class ComfortPlus : public Car {
public:
    ComfortPlus(std::string model, Coordinates currentCoordinates, CarColor color, std::string number);

protected:
    void setNumberOfBottles(int number);
    void decreaseNumberOfBottles();
    int getNumberOfBottles();

private:
    int numberOfBottles = 0;
};

#endif //WENDEXTAXI_COMFORTPLUS_H
