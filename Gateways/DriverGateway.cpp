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
    std::cout << driver.getName() << " changed status to " << currentStatus;
}

void DriverGateway::setOnlineStatus(Driver &driver, bool status) {
    driver.setOnlineStatus(status);
//    if (status)
//
//        else


    std::string currentStatus = status ? "online" : "offline";
    std::cout << driver.getName() << " changed status to " << currentStatus;
}

void DriverGateway::seeOrderHistory(Driver &driver) {
    std::cout << "\n Order history: \n";
    for (auto i : getOrderHistory(driver)) {
        std::cout << "From " << i.getFrom().getAddress() << " to " << i.getTo().getAddress() << " Cost: " << i.getPrice() << std::endl;
    }
}

