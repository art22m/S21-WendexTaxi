//
// Created by Artem Murashko on 14.04.2021.
//
#ifndef WENDEXTAXI_SYSTEM_H
#define WENDEXTAXI_SYSTEM_H

#include "../Orders/Order.h"
#include "../WendexMaps/Coordinates.h"
#include "../WendexMaps/Address.h"
#include "../Users/Passenger.h"
#include "../Users/Driver.h"
#include <vector>

class System {
public:
    static System* getInstance() {
        static System instance;
        return &instance;
    }

public:
    void deleteOnlineDrive(Driver driver);
    void addOnlineDriver(Driver driver);
    void deleteOrder(Order &order);
    void addOrder(Order &order);
    double getPrice(Address from, Address to, CarType carType);

private:
    std::vector <Order> activeOrders;
    std::vector <Driver> onlineDrivers;
    System();
};


#endif //WENDEXTAXI_SYSTEM_H
