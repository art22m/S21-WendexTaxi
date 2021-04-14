//
// Created by Artem Murashko on 10.04.2021.
//

#ifndef WENDEXTAXI_COORDINATES_H
#define WENDEXTAXI_COORDINATES_H

#include <random>

struct Coordinates {
    double x;
    double y;

    Coordinates(double x, double y) {
        this -> x = x;
        this -> y = y;
    }

    Coordinates() {
        std::uniform_real_distribution<double> unif(0, 100);
        std::default_random_engine re;
        auto dice {std::bind(unif, re)};

        this -> x = dice();
        this -> y = dice();
    }
};

#endif //WENDEXTAXI_COORDINATES_H
