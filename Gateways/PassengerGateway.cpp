//
// Created by Artem Murashko on 14.04.2021.
//

#include "PassengerGateway.h"
#include "../Users/Passenger.h"

PassengerGateway::PassengerGateway() {

}

void PassengerGateway::createOrder(Passenger &passenger, Address from, Address to, CarType type) {

}

/*
 * If we have Payment Method cash, then do it card and vice versa.
 */
void PassengerGateway::changePaymentMethod(Passenger &passenger) {
    if (passenger.getPaymentMethod() == PaymentMethods::card)
        passenger.setPaymentMethod(PaymentMethods::cash);
    else
        passenger.setPaymentMethod(PaymentMethods::card);
    std::cout << "\n Payment method added successfully \n";
}

void PassengerGateway::pinAddress(Passenger &passenger, Address address) {
    passenger.pinnedAddresses.push_back(address);
    std::cout << "\n Address added successfully \n";
}

std::vector<Address> PassengerGateway::getPinnedAddresses(Passenger &passenger) {
    return passenger.pinnedAddresses;
}

std::vector<Order> PassengerGateway::getOrderHistory(Passenger &passenger) {
    return passenger.getOrderHistory();
}
