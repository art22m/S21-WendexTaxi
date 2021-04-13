//
// Created by Артём Мурашко on 13.04.2021.
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

private:
    std::string name;
    double rating;
};


#endif //WENDEXTAXI_USER_H
