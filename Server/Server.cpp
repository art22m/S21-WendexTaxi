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

bool Server::isDriverValidated(string phoneNumber) {
    return DataBase::request() -> getDrivers()[phoneNumber] -> getValidationStatus();
}

bool Server::isDriverOnline(string phoneNumber) {
    return onlineDrivers[phoneNumber];
}

bool Server::isDriverPasswordCorrect(string phoneNumber, string password) {
    const string correctPassword = DataBase::request() -> getDrivers()[phoneNumber] -> getPassword();

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
    cout << endl << DataBase::request() -> getDrivers()[phoneNumber] -> getName() << " took order: "
         << availableOrders[response - 1].getAddressFrom().getAddress() <<  " -> " << availableOrders[response - 1].getAddressTo().getAddress()
         << ", Cost: " << availableOrders[response - 1].getPrice() << " rubles" << endl;
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
    string responseAddress;
    cout << endl << "You can change address_to to your pinned address. Do you want it?" << endl;
    cout << "Enter yes/no: "; cin >> responseAddress;
    // Make all letter in lower case
    for (auto &i: responseAddress)
        i = tolower(i);

    if (responseAddress == "yes") {
        vector <Address> pinnedAddresses = DataBase::request() -> getPassengers()[phoneNumber] -> getPinnedAddresses();
        if (pinnedAddresses.empty()) {
            cout << "You don't have any pinned addresses :(" << endl;
        } else {
            cout << endl << "You have " << pinnedAddresses.size() << " pinned addresses: " << endl;
            for (int id = 0; id < pinnedAddresses.size(); ++id)
                cout << "(" << id + 1 << ") " << pinnedAddresses[id].getAddress() << endl;
            int responsePinned;
            cout << "Enter number from 1 to " << pinnedAddresses.size() << ": "; cin >> responsePinned;
            if (responsePinned <= 0 || responsePinned > pinnedAddresses.size()) {
                cout << "Incorrect number." << endl;
            } else {
                Address chosenAddress = pinnedAddresses[responsePinned - 1];
                to = chosenAddress;
            }
        }
    }


    // Here we can call function for calculating the cost
    /* ---> Calculating cost and time <--- */
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
        cout << endl << "Your payment method is: " << DataBase::request() -> getPassengers()[phoneNumber] -> getPaymentMethodName() << endl;
        cout << "Do you wand to change it to " << (DataBase::request() -> getPassengers()[phoneNumber] -> getPaymentMethodName() == "cash?" ? "card" : "cash?") << endl;
        string responsePayment;
        cout << "Enter Yes/No: "; cin >> responsePayment;

        for (auto &i: responsePayment)
            i = tolower(i);

        if (responsePayment == "yes")
            DataBase::request() -> getPassengers()[phoneNumber] -> switchPaymentMethod();

        Order order(cost, timeOfRide, carType, from, to);
        addOrder(phoneNumber, order);
    } else {
        cout << "See you next time :)" << endl << endl;
    }
}

void Server::addOrder(string phoneNumber, Order order) {
    cout << "Order successfully created :)" << endl;
    activeOrders.push_back(order);
    DataBase::request() -> getPassengers()[phoneNumber] -> saveOrder(order);
}

/* ---> Admins Methods <--- */

void Server::adminEnter(string phoneNumber) {
    onlineAdmins[phoneNumber] = true;
    cout << "Admin successfully entered." << endl;
}

void Server::adminExit(string phoneNumber) {
    onlineAdmins[phoneNumber] = false;
    cout << "Admin successfully exited." << endl;
}

void Server::printDataBaseStatistics() {
    DataBase::request() -> printDataBaseStatistics();
}

void Server::registerAdmin(Admin *admin) {
    DataBase::request() -> addAdminEntity(admin);
}

bool Server::isAdminOnline(string phoneNumber) {
    return onlineAdmins[phoneNumber];
}

bool Server::isAdminPasswordCorrect(string phoneNumber, string password) {
    const string correctPassword = DataBase::request() -> getAdmins()[phoneNumber] -> getPassword();

    if (correctPassword == password)
        return true;
    else
        return false;
}

bool Server::isAdminRegistered(string phoneNumber) {
    map <string, Admin*> fetchedAdmins = DataBase::request() -> getAdmins();
    if (fetchedAdmins.find(phoneNumber) != fetchedAdmins.end())
        return true;
    else
        return false;
}

void Server::validateDriver(string phoneNumber) {
    DataBase::request() -> getDrivers()[phoneNumber] -> validateDriver();
    cout << "Driver successfully validated" << endl;
}
