//
// Created by Artem Murashko on 25.04.2021.
//

#ifndef WENDEXTAXI_ORDER_H
#define WENDEXTAXI_ORDER_H
#include "../Cars/CarType.h"
#include "../../WendexMaps.h"

class Order {
public:
    Order(double price, int time, CarType carType, Address from, Address to);

    double getPrice();
    int getTime();
    CarType getCarType();
    Address getAddressFrom();
    Address getAddressTo();

private:
    double price;
    int time;
    CarType carType;
    Address from;
    Address to;
};

#endif //WENDEXTAXI_ORDER_H