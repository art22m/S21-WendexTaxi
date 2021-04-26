//
// Created by Artem Murashko on 25.04.2021.
//
#include "Order.h"

Order::Order(double price, int time, CarType carType, Address from, Address to) {
    this -> price = price;
    this -> time = time;
    this -> carType = carType;
    this -> from = from;
    this -> to = to;
}

double Order::getPrice() {
    return price;
}

int Order::getTime() {
    return time;
}

CarType Order::getCarType() {
    return carType;
}

Address Order::getAddressFrom() {
    return from;
}

Address Order::getAddressTo() {
    return to;
}
