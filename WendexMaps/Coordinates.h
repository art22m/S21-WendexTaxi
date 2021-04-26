//
// Created by Artem Murashko on 25.04.2021.
//
#ifndef WENDEXTAXI_COORDINATES_H
#define WENDEXTAXI_COORDINATES_H

#include <random>
#include <time.h>

struct Coordinates {
    double x;
    double y;

    Coordinates(double x, double y) {
        this -> x = x;
        this -> y = y;
    }

    Coordinates() {
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_real_distribution<double> distr(1, 100);

        this -> x = distr(eng);
        this -> y = distr(eng);
    }
};


#endif //WENDEXTAXI_COORDINATES_H
