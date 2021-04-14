//
// Created by Artem Murashko on 14.04.2021.
//

#ifndef WENDEXTAXI_DRIVERGATEWAY_H
#define WENDEXTAXI_DRIVERGATEWAY_H

#include "../Users/User.h"
#include "../Users/Driver.h"
#include "../Service/System.h"
#include <vector>

class DriverGateway {
public:
    DriverGateway();

public:
    void seeOrderHistory(Driver &driver);
    void setBusyStatus(Driver &driver, bool status);
    void setOnlineStatus(Driver &driver, bool status);
    void checkAvailableOrder();
    void acceptOrder(Driver &driver);

    std::vector<Order> getOrderHistory(Driver &driver);
    bool getStatus(Driver &driver);
};

#endif //WENDEXTAXI_DRIVERGATEWAY_H
