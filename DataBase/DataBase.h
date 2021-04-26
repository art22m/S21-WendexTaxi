//
// Created by Artem Murashko on 26.04.2021.
//
#ifndef WENDEXTAXI_DATABASE_H
#define WENDEXTAXI_DATABASE_H

class Driver;
#include "../MobileApp/Users/Driver/Driver.h"
class Passenger;
#include "../MobileApp/Users/Passenger/Passenger.h"
class Admin;
#include "../MobileApp/Users/Admin/Admin.h"

#include "../MobileApp/Orders/Order.h"

#include <map>

using namespace std;

/*-- Singleton class Data Base --*/

class DataBase {
public:
    static DataBase* request() {
        static DataBase instance;
        return &instance;
    }

public:
    map <string, Driver*> getDrivers();
    map <string, Passenger*> getPassengers();
    map <string, Admin*> getAdmins();

public:
    void addDriverEntity(Driver *driver);
    void addPassengerEntity(Passenger *passenger);
    void addAdminEntity(Admin *admin);

public:
    void printDataBaseStatistics(); // Print the number of users in the DataBase

private:
    map <string, Driver*> drivers;
    map <string, Passenger*> passengers;
    map <string, Admin*> admins;

    DataBase();
};


#endif //WENDEXTAXI_DATABASE_H
