//
// Created by Artem Murashko on 25.04.2021.
//
#include "Car.h"

Car::Car(string model, string color, string licencePlate, CarType carType, Coordinates coordinates) {
    this -> model = model;
    this -> color = color;
    this -> licencePlate = licencePlate;
    this -> carType = carType;
    this -> coordinates = coordinates;
}

Car::Car(string model, string color, string licencePlate, CarType carType) {
    this -> model = model;
    this -> color = color;
    this -> licencePlate = licencePlate;
    this -> carType = carType;
    coordinates = Coordinates();
}

string Car::getModel() {
    return model;
}

string Car::getColor() {
    return color;
}

string Car::getLicencePLate() {
    return licencePlate;
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