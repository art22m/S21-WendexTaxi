//
// Created by Artem Murashko on 25.04.2021.
//
#include "User.h"

User::User(string name, string phoneNumber, string password, double rating) {
    this -> name = name;
    this -> phoneNumber = phoneNumber;
    this -> password = password;
    this -> rating = rating;
}

User::User() { }

string User::getPhoneNumber() {
    return phoneNumber;
}

string User::getName() {
    return name;
}

string User::getPassword() {
    return password;
}

double User::getRating() {
    return rating;
}

void User::saveOrder(Order order) {
    orders.push_back(order);
}
