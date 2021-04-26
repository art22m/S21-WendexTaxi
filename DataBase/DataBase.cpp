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

map <string, Admin *> DataBase::getAdmins() {
    return admins;
}

// ----------

void DataBase::addDriverEntity(Driver *driver) {
    drivers[driver -> getPhoneNumber()] = driver;
    cout << "Driver successfully registered." << endl;
}

void DataBase::addPassengerEntity(Passenger *passenger) {
    passengers[passenger -> getPhoneNumber()] = passenger;
    cout << "Passenger successfully registered." << endl;
}

void DataBase::addAdminEntity(Admin *admin) {
    admins[admin -> getPhoneNumber()] = admin;
    cout << "Admin successfully registered." << endl;
}

// --------

void DataBase::printDataBaseStatistics() {
    cout << "There are " << drivers.size() + passengers.size() + admins.size() << " users in the data base" << endl;
    cout << "Number of admins: " << admins.size() << endl;
}

