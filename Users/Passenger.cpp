//
// Created by Artem Murashko on 10.04.2021.
//

#include "Passenger.h"

Passenger::Passenger(std::string name, double rating) : User(name, rating) {
    paymentMethod = PaymentMethods::card;
}

/*
 * If we have Payment Method cash, then do it card and vice versa.
 */
void Passenger::changePaymentMethod() {
    if (paymentMethod == PaymentMethods::card)
        paymentMethod = PaymentMethods::cash;
    else
        paymentMethod = PaymentMethods::card;
}

void Passenger::pinAddress(const Address& address) {
    pinnedAddresses.push_back(address);
    std::cout << "\n Address added successfully \n";
}

std::vector<Address> Passenger::getPinnedAddresses() {
    return pinnedAddresses;
}

void Passenger::addOrder(const Order& order) {
    orderHistory.push_back(order);
    std::cout << "\n Order added successfully \n";
}

std::vector<Order> Passenger::getOrderHistory() {
    return orderHistory;
}