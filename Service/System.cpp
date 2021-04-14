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

void System::addOrder(Order order) {
    for (auto &driver : onlineDrivers) {
//        std::cout << order.getCarType() << "\n";
        if (driver.getCar().getCarType() == order.getCarType()) {
            std::cout << driver.getName() << " took order \n";
            driver.addOrder(order);
            return;
        }
    }

    activeOrders.push_back(order);
    std::cout << "There are no free drivers \n";
}

void System::deleteOnlineDrive(Driver driver) {
    for (int i = 0; i < onlineDrivers.size(); ++i)
        if (onlineDrivers[i].getPhoneNumber() == driver.getPhoneNumber())
            onlineDrivers.erase(onlineDrivers.begin() + i);
}

void System::deleteOrder(Order &order) {
    for (int i = 0; i < activeOrders.size(); ++i)
        if (activeOrders[i].getPrice() == order.getPrice())
            activeOrders.erase(activeOrders.begin() + i);
}

double System::getPrice(Address from, Address to, CarType carType) {
    double distance = sqrt( pow(from.getCoordinates().x - to.getCoordinates().x, 2) + pow(from.getCoordinates().y - to.getCoordinates().y, 2));
    double price = distance * (double) carType;

    return price;
}

std::vector<Order> System::getActiveOrders() {
    return activeOrders;
}

System::System() {

}

int System::getNumberOfActiveOrders() {
    return activeOrders.size();
}

void System::findAvailableOrder(Driver &driver) {
    for (auto order: activeOrders) {
        if (order.getCarType() == driver.getCar().getCarType()) {
            std::cout << driver.getName() << " took order \n";
            driver.addOrder(order);
            return;
        }
    }

    std::cout << "There are no available drivers \n";
}
