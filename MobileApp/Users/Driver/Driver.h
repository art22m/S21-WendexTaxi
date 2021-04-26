//
// Created by Artem Murashko on 25.04.2021.
//
#ifndef WENDEXTAXI_DRIVER_H
#define WENDEXTAXI_DRIVER_H

#include "../User.h"
class DriverGateway;
#include "../../../Gateways/DriverGateway/DriverGateway.h"

class Driver : public User {
public:
    Driver(string name, string phoneNumber, string password, double rating);
    Driver(string name, string phoneNumber, string password);
    Driver();

public:
    void enter(string password);
    void exit();
    void registerAccount();
    void registerCar(Car car); // Registers a car with a request to the server
    void addCar(Car *car); // Add the car to the array of cars
    void findOrder();
    void changeCurrentCar();
    Car* getCurrentCar();
    int getNumberOfCars();
private:
    vector <Car*> cars;
    Car *currentCar = nullptr;
    int numberOfRides;

private:
    DriverGateway *gateway;
};


#endif //WENDEXTAXI_DRIVER_H
