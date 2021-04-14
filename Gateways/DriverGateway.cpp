//
// Created by Artem Murashko on 14.04.2021.
//

#include "DriverGateway.h"

DriverGateway::DriverGateway() {

}

std::vector<Order> DriverGateway::getOrderHistory(Driver &driver) {
    return driver.getOrderHistory();
}

bool DriverGateway::getStatus(Driver &driver) {
    return driver.getBusyStatus();
}

void DriverGateway::setBusyStatus(Driver &driver, bool status) {
    driver.setBusyStatus(status);
    std::string currentStatus = status ? "busy" : "free";
    std::cout << "\n" << driver.getName() << " changed status to " << currentStatus << "\n";
}

void DriverGateway::setOnlineStatus(Driver &driver, bool status) {
    driver.setOnlineStatus(status);
    if (status) {
        System::getInstance() -> addOnlineDriver(driver);
    } else {
        System::getInstance() -> deleteOnlineDrive(driver);
    }

    std::string currentStatus = status ? "online" : "offline";
    std::cout << driver.getName() << " changed status to " << currentStatus << "\n";
}

void DriverGateway::seeOrderHistory(Driver &driver) {
    std::cout << "\nOrder history: \n";
    for (auto i : getOrderHistory(driver)) {
        std::cout << "From " << i.getFrom().getAddress() << " to " << i.getTo().getAddress() << " Cost: " << i.getPrice() << std::endl;
    }
}

void DriverGateway::checkAvailableOrders() {
    std::cout << "\nAvailable orders: \n";

    if (System::getInstance() -> getNumberOfActiveOrders() == 0) {
        std::cout << "There are no orders \n";
        return;
    }

    for (auto order : System::getInstance() -> getActiveOrders())
        std::cout << order.getFrom().getAddress() << " " << order.getTo().getAddress() << " " << order.getPrice() << std::endl;
}

void DriverGateway::findOrder(Driver &driver) {
    System::getInstance() ->findAvailableOrder(driver);
}
