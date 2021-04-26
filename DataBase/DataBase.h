//
// Created by Artem Murashko on 26.04.2021.
//
#ifndef WENDEXTAXI_DATABASE_H
#define WENDEXTAXI_DATABASE_H

class Driver;
#include "../MobileApp/Users/Driver/Driver.h"
class Passenger;
#include "../MobileApp/Users/Passenger/Passenger.h"

#include "../MobileApp/Orders/Order.h"

#include <map>

using namespace std;


class DataBase {
public:
    static DataBase* request() {
        static DataBase instance;
        return &instance;
    }

public:
    map <string, Driver*> getDrivers();
    map <string, Passenger*> getPassengers();

public:
    void addDriverEntity(Driver *driver);
    void addPassengerEntity(Passenger *passenger);

private:
    map <string, Driver*> drivers;
    map <string, Passenger*> passengers;

    DataBase();
};


#endif //WENDEXTAXI_DATABASE_H
