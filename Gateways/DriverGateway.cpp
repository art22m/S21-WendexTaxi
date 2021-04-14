//
// Created by Artem Murashko on 14.04.2021.
//

#include "DriverGateway.h"
#include "../Users/Driver.h"

DriverGateway::DriverGateway() {

}

std::vector<Order> DriverGateway::getOrderHistory(Driver &driver) {
    return driver.getOrderHistory();
}

bool DriverGateway::getStatus(Driver &driver) {
    return driver.isBusy;
}

void DriverGateway::setStatus(Driver &driver, bool status) {
    driver.isBusy = status;
}

