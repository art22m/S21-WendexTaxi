//
// Created by Артём Мурашко on 10.04.2021.
//

#ifndef WENDEXTAXI_COORDINATES_H
#define WENDEXTAXI_COORDINATES_H

struct Coordinates {
    double x;
    double y;

    Coordinates(double x, double y) {
        this -> x = x;
        this -> y = y;
    }

    Coordinates() {
        this -> x = 0;
        this -> y = 0;
    }
};
#endif //WENDEXTAXI_COORDINATES_H
