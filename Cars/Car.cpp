//
// Created by Artem Murashko on 10.04.2021.
//

#include "Car.h"

Car::Car(std::string model, CarType carType, Coordinates currentCoordinates, CarColor color, std::string number) {
    this -> model = model;
    this -> carType = carType;
    this -> currentCoordinates = currentCoordinates;
    this -> color = color;
    this -> number = number;
}

std::string Car::getModel() {
    return model;
}

CarType Car::getCarType() {
    return carType;
}

std::string Car::getCarTypeName() {
    switch (getCarType()) {
        case CarType::economy:
            return "Economy";
        case CarType::comfort:
            return "Comfort";
        case CarType::comfortPlus:
            return "Comfort Plus";
        case CarType::business:
            return "Business";
    }
}

Coordinates Car::getCurrentCoordinates() {
    return Coordinates(currentCoordinates.x, currentCoordinates.y);
}

CarColor Car::getCarColor() {
    return color;
}

std::string Car::getCarColorName() {
    switch (getCarColor()) {
        case CarColor::blue:
            return "Blue";
        case CarColor::red:
            return "Red";
        case CarColor::white:
            return "White";
        case CarColor::yellow:
            return "Yellow";
        case CarColor::black:
            return "Black";
    }
}

std::string Car::getNumber() {
    return number;
}



