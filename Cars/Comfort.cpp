//
// Created by Artem Murashko on 10.04.2021.
//

#include "Comfort.h"

Comfort::Comfort(std::string model, Coordinates currentCoordinates, CarColor color, std::string number) :
        Car(model, CarType::comfort, currentCoordinates, color, number) {
    numberOfBottles = 1;
}

void Comfort::setNumberOfBottles(int number) {
    numberOfBottles = number;
}

void Comfort::decreaseNumberOfBottles() {
    if (getNumberOfBottles() == 0) {
        std::cout << "There are no bottles left\n";
        return;
    }
    numberOfBottles -= rand() % numberOfBottles;
}

int Comfort::getNumberOfBottles() {
    return numberOfBottles;
}