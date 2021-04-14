//
// Created by Artem Murashko on 14.04.2021.
//

#include "PassengerGateway.h"
#include "../Users/Passenger.h"

PassengerGateway::PassengerGateway() {

}

/*
 * If we have Payment Method cash, then do it card and vice versa.
 */
void PassengerGateway::changePaymentMethod(Passenger &passenger) {
    if (passenger.getPaymentMethod() == PaymentMethods::card)
        passenger.setPaymentMethod(PaymentMethods::cash);
    else
        passenger.setPaymentMethod(PaymentMethods::card);
    std::cout << "\nPayment method added successfully \n";
}

void PassengerGateway::pinAddress(Passenger &passenger, Address address) {
    passenger.pinnedAddresses.push_back(address);
    std::cout << "\nAddress added successfully \n";
}

std::vector<Address> PassengerGateway::getPinnedAddresses(Passenger &passenger) {
    return passenger.pinnedAddresses;
}

std::vector<Order> PassengerGateway::getOrderHistory(Passenger &passenger) {
    return passenger.getOrderHistory();
}

void PassengerGateway::seeOrderHistory(Passenger &passenger) {
    std::cout << "\nOrder history: \n";
    for (auto i : getOrderHistory(passenger)) {
        std::cout << "From " << i.getFrom().getAddress() << " to " << i.getTo().getAddress() << " Cost: " << i.getPrice() << std::endl;
    }
}

void PassengerGateway::seePinnedAddresses(Passenger &passenger) {
    std::cout << "\nPinned addresses: \n";
    for (auto i : getPinnedAddresses(passenger)) {
        std::cout << "From " << i.getAddress() << std::endl;
    }
}

void PassengerGateway::createOrder(Passenger &passenger, Address from, Address to, CarType type) {
    double rideCost = System::getInstance() -> getPrice(from, to, type);

    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> distr(1, 100);

    double time = distr(eng);

    std::cout << "\nPrice of ride will be " << rideCost << " rubles.\nTime: " << time << " minutes \n";

    bool isAccept = true; // User's answer should be here
    if (isAccept) {
        std::cout << "\n" << passenger.getName() << " agree with the terms of the ride\n";
        Order order(from, to, rideCost, time, type);
        passenger.addOrder(order);
        System::getInstance() -> addOrder(order);
    }
}

void PassengerGateway::askCurrentCoordinates(Passenger &passenger) {
    std::uniform_real_distribution<double> unif(0, 100);
    std::default_random_engine re;
    auto dice {std::bind(unif, re)};

    std::cout << "\nCurrent coordinates: \n" << "x = " << dice() << " y = " << dice() << std::endl;
}

void PassengerGateway::askBill(Passenger &passenger) {

}
