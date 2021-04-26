//
// Created by Artem Murashko on 25.04.2021.
//
#include "Server.h"
#include <ctime>

Server::Server() {
    // Used to create random numbers
    srand(time(NULL));
}

/*-----> Driver Methods <-----*/

bool Server::isDriverRegistered(string phoneNumber) {
    map <string, Driver*> fetchedDivers = DataBase::request() -> getDrivers();
    if (fetchedDivers.find(phoneNumber) != fetchedDivers.end())
        return true;
    else
        return false;
}

bool Server::isDriverOnline(string phoneNumber) {
    return onlineDrivers[phoneNumber];
}

bool Server::isDriverPasswordCorrect(string number, string password) {
    const string correctPassword = DataBase::request() -> getDrivers()[number] -> getPassword();

    if (correctPassword == password)
        return true;
    else
        return false;
}

void Server::driverEnter(string phoneNumber) {
    onlineDrivers[phoneNumber] = true;
    cout << "Driver successfully entered." << endl;
}

void Server::driverExit(string phoneNumber) {
    onlineDrivers[phoneNumber] = false;
    cout << "Driver successfully exited." << endl;
}

void Server::registerDriver(Driver *driver) {
    DataBase::request() -> addDriverEntity(driver);
}

void Server::findOrder(string phoneNumber) {
    vector <Order> availableOrders; // available orders for current driver
    CarType currentCarType = getCurrentCar(phoneNumber) -> getCarType();

    for (int i = 0; i < activeOrders.size(); ++i)
        if (activeOrders[i].getCarType() == currentCarType)
            availableOrders.push_back(activeOrders[i]);

    if (availableOrders.size() == 0) {
        cout << "There are no available orders for car type: "
        << DataBase::request() -> getDrivers()[phoneNumber] -> getCurrentCar() -> getCarTypeName() << endl;
        cout << "Try again later or choose a car with another car type." << endl;
        return;
    }

    cout << "There are " << availableOrders.size() << " available orders" << endl;

    for (int index = 0; index < availableOrders.size(); ++index) {
        cout << "(" << index + 1 << ") From: " << availableOrders[index].getAddressFrom().getAddress()
        << " To: " << availableOrders[index].getAddressTo().getAddress() << " Cost: " << availableOrders[index].getPrice()
        << " rubles Time: " << availableOrders[index].getTime() << " minutes" << endl;
    }

    cout << "Choose from 1 to " << availableOrders.size() << ": ";
    int response;
    cin >> response;

    if (response <= 0 || response > availableOrders.size()) {
        cout << "Incorrect number. Try again." << endl;
        return;
    }

    int foundIndex = - 1; // index of chosen order in the active oreders
    for (int index = 0; index < activeOrders.size(); ++index) {
        if (activeOrders[index].getPrice() == availableOrders[response - 1].getPrice() &&
            activeOrders[index].getAddressFrom().getAddress() == availableOrders[response - 1].getAddressFrom().getAddress() &&
            activeOrders[index].getAddressTo().getAddress() == availableOrders[response - 1].getAddressTo().getAddress())
        {
            foundIndex = index;
            break;
        }
    }

    if (foundIndex == -1) {
        cout << "Ops, someone took this order." << endl;
        cout << "Please, choose another order." << endl;
        return;
    }

    activeOrders.erase(activeOrders.begin() + foundIndex);
    DataBase::request() -> getDrivers()[phoneNumber] -> saveOrder(availableOrders[response - 1]);
    cout << endl << DataBase::request() -> getDrivers()[phoneNumber] -> getName() << " took order "
         << availableOrders[response - 1].getAddressFrom().getAddress() <<  " -> " << availableOrders[response - 1].getAddressTo().getAddress()
         << " Cost: " << availableOrders[response - 1].getPrice() << " rubles" << endl;
}

void Server::addCar(string phoneNumber, Car *car) {
    DataBase::request() -> getDrivers()[phoneNumber] -> addCar(car);
    cout << "Car successfully registered." << endl;
}

bool Server::isDriverHasCars(string phoneNumber) {
    if (DataBase::request() -> getDrivers()[phoneNumber] -> getNumberOfCars() > 0)
        return true;
    else
        return false;
}

Car *Server::getCurrentCar(string phoneNumber) {
    return DataBase::request() -> getDrivers()[phoneNumber] -> getCurrentCar();
}

/*-----> Passenger Methods <-----*/

bool Server::isPassengerPasswordCorrect(string phoneNumber, string password) {
    const string correctPassword = DataBase::request() -> getPassengers()[phoneNumber] -> getPassword();

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