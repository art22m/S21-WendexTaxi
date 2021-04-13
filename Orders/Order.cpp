//
// Created by Артём Мурашко on 13.04.2021.
//

#include "Order.h"

Order::Order(Address from, Address to, double price, int time) {
    this -> from = from;
    this -> to = to;
    this -> price = price;
    this -> time = time;
}

Address Order::getFrom() {
    return from;
}

Address Order::getTo() {
    return to;
}

double Order::getPrice() {
    return price;
}

int Order::getTime() {
    return time;
}
