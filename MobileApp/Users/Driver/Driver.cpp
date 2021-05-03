//
// Created by Artem Murashko on 25.04.2021.
//
#include "Driver.h"

Driver::Driver(string name, string phoneNumber, string password, double rating) : User(name, phoneNumber, password, rating) { }
Driver::Driver(string name, string phoneNumber, string password) : User(name, phoneNumber, password) { }
Driver::Driver() { }

void Driver::enter(string password) {
    gateway -> driverEnter(getPhoneNumber(), password);
}

void Driver::exit() {
    gateway -> driverExit(getPhoneNumber());
}

void Driver::registerAccount() {
    gateway -> registerDriver(this);
}

void Driver::registerCar(Car car) {
    gateway -> addCar(getPhoneNumber(), &car);
}

void Driver::addCar(Car *car) {
    cars.push_back(car);
}

void Driver::findOrder() {
    gateway -> findOrder(getPhoneNumber());
}

void Driver::changeCurrentCar() {
    if (cars.size() == 0) {
        cout << "You don't have any registered cars!" << endl;
        return;
    }

    cout << endl << "Your registered cars:" << endl;
    for (int index = 0; index < cars.size(); ++index) {
        cout << "(" << index + 1 << ")" << " " << cars[index] -> getModel() << " "
             << cars[index] -> getLicencePLate() << " " << cars[index] -> getCarTypeName() << endl;
    }
    cout << "Choose from 1 to " << cars.size() << ": ";
    int response = 0;
    cin >> response;

    if (response <= 0 || response > cars.size()) {
        cout << "Incorrect number. Try again." << endl;
        return;
    }

    currentCar = cars[response - 1];
    cout << currentCar -> getModel() << " successfully chose." << endl << endl;
}

int Driver::getNumberOfCars() {
    return cars.size();
}

Car *Driver::getCurrentCar() {
    return currentCar;
}

void Driver::validateDriver() {
    isValidated = true;
}

bool Driver::getValidationStatus() {
    return isValidated;
}
