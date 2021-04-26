#include "WendexTaxi.h"

using namespace std;
int main() {
    // ---> Register first passenger account <--- //
    Passenger p1("Artem Chernitsa", "+7123", "Sosiska123", 5);
    p1.enter("Sos");
    p1.registerAccount();
    p1.enter("SOs");
    p1.enter("Sosiska123");
    p1.registerAccount();
    p1.makeOrder(Address("Ulitsa Lenina", Coordinates()), Address("Prospect Izmailovo", Coordinates()), CarType::economy);

    // ---> Register first driver account <--- //
    Driver d1("Seva Mikulik", "+7927", "Krendel333");
    d1.enter("qwerty");
    d1.registerAccount();
    d1.registerAccount();
    d1.enter("qwerty");
    d1.exit();
    d1.findOrder();
    d1.enter("Krendel333");
    d1.findOrder();
    Car c1("Ranault Logan", "yellow", "AV122E", CarType::economy);
    d1.registerCar(c1);
    d1.findOrder();
    Car c2("Ranault Almeta", "yellow", "AV121E", CarType::comfortPlus);
    d1.registerCar(c2);
    d1.changeCurrentCar();
    d1.findOrder();

    return 0;
}
