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


