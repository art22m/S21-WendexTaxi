//
// Created by Artem Murashko on 14.04.2021.
//

#ifndef WENDEXTAXI_DRIVERGATEWAY_H
#define WENDEXTAXI_DRIVERGATEWAY_H

#include "../Users/User.h"
#include <vector>

class Driver;

class DriverGateway {
public:
    DriverGateway();

public:
    std::vector<Order> getOrderHistory(Driver &driver);
    bool getStatus(Driver &driver);
    void setStatus(Driver &driver, bool status);
};


#endif //WENDEXTAXI_DRIVERGATEWAY_H
