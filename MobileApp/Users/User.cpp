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
User::User(string name, string phoneNumber, string password) {
    this -> name = name;
    this -> phoneNumber = phoneNumber;
    this -> password = password;
    rating = 5.0;
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

void User::seeOrderHistory() {
    if (orders.size() == 0) {
        cout << "You don't have any orders :)" << endl;
        return;
    }
    cout << "Order history: " << endl;
    for (int id = 0; id < orders.size(); ++id)
        cout << "(" << id << ") From: " << orders[id].getAddressFrom().getAddress() << " To: "
             << orders[id].getAddressTo().getAddress() << " Cost: " << orders[id].getPrice() << " rubles" << endl;

}
