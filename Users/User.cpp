//
// Created by Artem Murashko on 13.04.2021.
//

#include "User.h"

User::User(std::string name, double rating, std::string phoneNumber) {
    this -> name = name;
    this -> rating = rating;
    this -> phoneNumber = phoneNumber;
}

std::string User::getName() {
    return name;
}

double User::getRating() {
    return rating;
}

void User::changeRating(double rate) {
    rating += rate;
}

void User::addOrder(const Order& order) {
    orderHistory.push_back(order);
    std::cout << "\n Order added successfully \n";
}

std::vector<Order> User::getOrderHistory() {
    return orderHistory;
}

std::string User::getPhoneNumber() {
    return phoneNumber;
}
