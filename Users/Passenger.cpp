//
// Created by Artem Murashko on 10.04.2021.
//

#include "Passenger.h"

Passenger::Passenger(std::string name, double rating, std::string phoneNumber) : User(name, rating, phoneNumber) {
    paymentMethod = PaymentMethods::card;
}

PaymentMethods Passenger::getPaymentMethod() {
    return paymentMethod;
}

void Passenger::setPaymentMethod(PaymentMethods newPaymentMethod) {
    paymentMethod = newPaymentMethod;
}
