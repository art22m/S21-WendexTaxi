#include <iostream>
#include "Cars/Car.h"
#include "Cars/Economy.h"
#include "Cars/Comfort.h"
using namespace std;
int main() {
    Comfort myCar("Kia Optima", Coordinates(1, 2), CarColor::black, "A777AB");

    cout << myCar.getModel() << endl;
    cout << myCar.getNumber() << endl;
    cout << myCar.getCarColorName() << endl;
    cout << myCar.getCarTypeName() << endl;
    cout << myCar.getCurrentCoordinates().x << " ";
    cout << myCar.getCurrentCoordinates().y << endl;
    return 0;
}
