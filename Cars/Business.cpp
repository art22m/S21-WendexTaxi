//
// Created by Артём Мурашко on 10.04.2021.
//

#include "Business.h"

Business::Business(std::string model, Coordinates currentCoordinates, CarColor color, std::string number) :
        Car(model, CarType::comfortPlus, currentCoordinates, color, number) {
    isParkRightInFrontOfTheEntrance = false;
    numberOfBottles = 1;
}

void Business::parkRightInFrontOfTheEntrance() {
    if (isParkRightInFrontOfTheEntrance) {
        isParkRightInFrontOfTheEntrance = false;
        std::cout << "Option OFF \n";
    } else {
        isParkRightInFrontOfTheEntrance = true;
        std::cout << "Option ON \n";
    }
}

void Business::setNumberOfBottles(int number) {
    numberOfBottles = number;
}

void Business::decreaseNumberOfBottles() {
    if (getNumberOfBottles() == 0) {
        std::cout << "There are no bottles left\n";
        return;
    }
    numberOfBottles -= rand() % numberOfBottles;
}

int Business::getNumberOfBottles() {
    return numberOfBottles;
}
