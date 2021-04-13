//
// Created by Artem Murashko on 10.04.2021.
//

#ifndef WENDEXTAXI_COMFORT_H
#define WENDEXTAXI_COMFORT_H

#include "Car.h"

class Comfort : public Car {
public:
    Comfort(std::string model, Coordinates currentCoordinates, CarColor color, std::string number);

protected:
    void setNumberOfBottles(int number);
    void decreaseNumberOfBottles();
    int getNumberOfBottles();

private:
    int numberOfBottles = 0;
};

#endif //WENDEXTAXI_COMFORT_H
