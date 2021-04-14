//
// Created by Artem Murashko on 13.04.2021.
//

#ifndef WENDEXTAXI_ORDER_H
#define WENDEXTAXI_ORDER_H

#include "../WendexMaps/Address.h"
#include "../Cars/CarType.h"

class Order {
public:
    Order(Address from, Address to, double price, int time);

public:
    Address getFrom();
    Address getTo();
    double getPrice();
    int getTime();
    CarType getCarType();

private:
    Address from;
    Address to;
    double price;
    int time;
    CarType carType;
};


#endif //WENDEXTAXI_ORDER_H
