//
// Created by Artem Murashko on 10.04.2021.
//

#include "Economy.h"

Economy::Economy(std::string model, Coordinates currentCoordinates, CarColor color, std::string number) :
             Car(model, CarType::economy, currentCoordinates, color, number) {

}