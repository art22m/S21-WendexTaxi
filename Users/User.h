//
// Created by Artem Murashko on 13.04.2021.
//

#ifndef WENDEXTAXI_USER_H
#define WENDEXTAXI_USER_H

#include <string>
#include <iostream>
#include <vector>

#include "../WendexMoney/PaymentMethods.h"
#include "../WendexMaps/Address.h"
#include "../Orders/Order.h"

class User {
protected:
    User(std::string name, double rating);

public:
    std::string getName();
    double getRating();
    void changeRating(double rate);
    void addOrder(const Order& order);
    std::vector <Order> getOrderHistory();

private:
    std::string name;
    double rating;
    std::vector <Order> orderHistory;
};


#endif //WENDEXTAXI_USER_H
