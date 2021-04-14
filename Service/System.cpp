//
// Created by Artem Murashko on 14.04.2021.
//
#include "System.h"

void System::addOnlineDriver(Driver driver) {
    for (auto i : onlineDrivers)
        if (i.getPhoneNumber() == driver.getPhoneNumber()) {
            std::cout << "Driver already online \n";
            return;;
        }

    onlineDrivers.push_back(driver);
}

void System::addOrder(Order &order) {
    activeOrders.push_back(order);
}

void System::deleteOnlineDrive(Driver driver) {
    for (int i = 0; i < onlineDrivers.size(); ++i)
        if (onlineDrivers[i].getPhoneNumber() == driver.getPhoneNumber())
            onlineDrivers.erase(onlineDrivers.begin() + i);
}

void System::deleteOrder(Order &order) {

}

double System::getPrice(Address from, Address to, CarType carType) {
    double distance = sqrt( pow(from.getCoordinates().x - to.getCoordinates().x, 2) + pow(from.getCoordinates().y - to.getCoordinates().y, 2));
    double price = distance * (double) carType;

    return price;
}

System::System() {

}
