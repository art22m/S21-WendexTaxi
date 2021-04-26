//
// Created by Artem Murashko on 25.04.2021.
//
#ifndef WENDEXTAXI_USER_H
#define WENDEXTAXI_USER_H

#include <iostream>
#include "../Orders/Order.h"
#include "../Cars/Car.h"

using namespace std;

class User {
public:
    User(string name, string phoneNumber, string password, double rating);
    User();

public:
    string getName();
    string getPassword();
    string getPhoneNumber();
    double getRating();
    void saveOrder(Order order);

private:
    string name;
    string password;
    string phoneNumber;
    double rating;
    vector <Order> orders;
};


#endif //WENDEXTAXI_USER_H