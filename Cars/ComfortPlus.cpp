//
// Created by Artem Murashko on 10.04.2021.
//

#include "ComfortPlus.h"

ComfortPlus::ComfortPlus(std::string model, Coordinates currentCoordinates, CarColor color, std::string number) :
        Car(model, CarType::comfortPlus, currentCoordinates, color, number) {
    numberOfBottles = 1;
}

void ComfortPlus::setNumberOfBottles(int number) {
    numberOfBottles = number;
}

void ComfortPlus::decreaseNumberOfBottles() {
    if (getNumberOfBottles() == 0) {
        std::cout << "There are no bottles left\n";
        return;
    }
    numberOfBottles -= rand() % numberOfBottles;
}

int ComfortPlus::getNumberOfBottles() {
    return numberOfBottles;
}