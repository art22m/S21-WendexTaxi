//
// Created by Artem Murashko on 26.04.2021.
//
#include "DataBase.h"

DataBase::DataBase() { }

map <string, Driver*> DataBase::getDrivers() {
    return drivers;
}

map <string, Passenger*> DataBase::getPassengers() {
    return passengers;
}

void DataBase::addDriverEntity(Driver *driver) {
    drivers[driver -> getPhoneNumber()] = driver;
    cout << "Driver successfully registered." << endl;
}

void DataBase::addPassengerEntity(Passenger *passenger) {
    passengers[passenger -> getPhoneNumber()] = passenger;
    cout << "Passenger successfully registered." << endl;
}
