//
// Created by Artem Murashko on 25.04.2021.
//
#include "Server.h"
#include <ctime>

Server::Server() {
    // Used to create random numbers
    srand(time(NULL));
}

/*-----> Passenger Methods <-----*/

bool Server::isPassengerPasswordCorrect(string number, string password) {
    const string correctPassword = DataBase::request() -> getPassengers()[number] -> getPassword();

    if (correctPassword == password)
        return true;
    else
        return false;
}

bool Server::isPassengerOnline(string phoneNumber) {
    return onlinePassengers[phoneNumber];
}

bool Server::isPassengerRegistered(string phoneNumber) {
    map <string, Passenger*> fetchedPassengers = DataBase::request() -> getPassengers();
    if (fetchedPassengers.find(phoneNumber) != fetchedPassengers.end())
        return true;
    else
        return false;
}

void Server::registerPassenger(Passenger *passenger) {
    DataBase::request() -> addPassengerEntity(passenger);
}

void Server::passengerExit(string phoneNumber) {
    onlinePassengers[phoneNumber] = false;
    cout << "Passenger successfully exited." << endl;
}

void Server::passengerEnter(string phoneNumber) {
    onlinePassengers[phoneNumber] = true;
    cout << "Passenger successfully entered." << endl;
}


void Server::getOrderInfo(string phoneNumber, Address from, Address to, CarType carType) {
    // Here we can call function for calculating the cost
    /* ---> Calculating cost and time<--- */
    double distance = (from.getCoordinates().x - to.getCoordinates().x) * (from.getCoordinates().x - to.getCoordinates().x)
                    + (from.getCoordinates().y - to.getCoordinates().y) * (from.getCoordinates().y - to.getCoordinates().y);
    double cost = 0;
    switch (carType) {
        case CarType::economy:
            cost = distance * 1.2;
            break;
        case CarType::comfort:
            cost = distance * 1.8;
            break;
        case CarType::comfortPlus:
            cost = distance * 2.5;
            break;
        case CarType::business:
            cost = distance * 4;
            break;
    }
    int timeOfRide = rand() % 100;
    cout << endl << "The ride from " << from.getAddress() << " to " << to.getAddress() << " will cost " << cost << " rubles" <<  endl;
    cout << "Ride time: " << timeOfRide << " minutes" << endl;
    cout << "Do you agree?" << endl;

    string response;
    cout << "Enter Yes/No: "; cin >> response;

    // Make all letter in lower case
    for (auto &i: response)
        i = tolower(i);

    if (response == "yes") {
        Order order(cost, timeOfRide, carType, from, to);
        addOrder(phoneNumber, order);
    } else {
        cout << "See you next time :)" << endl << endl;
    }
}

void Server::addOrder(string phoneNumber, Order order) {
    cout << "Order successfully created :)" << endl << endl;
    activeOrders.push_back(order);
    DataBase::request() -> getPassengers()[phoneNumber] -> saveOrder(order);
}