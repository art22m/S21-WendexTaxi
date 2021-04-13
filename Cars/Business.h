//
// Created by Artem Murashko on 10.04.2021.
//

#ifndef WENDEXTAXI_BUSINESS_H
#define WENDEXTAXI_BUSINESS_H

#include "Car.h"

class Business : public Car {
public:
    Business(std::string model, Coordinates currentCoordinates, CarColor color, std::string number);

protected:
    void parkRightInFrontOfTheEntrance();
    void setNumberOfBottles(int number);
    void decreaseNumberOfBottles();
    int getNumberOfBottles();

private:
    bool isParkRightInFrontOfTheEntrance;
    int numberOfBottles;
};


#endif //WENDEXTAXI_BUSINESS_H
