#include "WendexTaxi.h"

Passenger p1("Artem Chernitsa", "+7123", "Sosiska123");
Passenger p2("Ivan Razbil", "+7992", "PekaPeka");
Driver d1("Seva Mikulik", "+7927", "Krendel333");
Admin a1("Artem Murashko", "+7534", "Qeqeq");

using namespace std;
int main() {
//    // ---> Register first passenger account <--- //
//    p1.enter("Sos");
//    p1.registerAccount();
//    p1.enter("SOs");
//    p1.enter("Sosiska123");
//    p1.registerAccount();
//    p1.pinAddress(Address("Egoriev Proezd", Coordinates()));
//    p1.makeOrder(Address("Ulitsa Lenina", Coordinates()), Address("Prospect Izmailovo", Coordinates()), CarType::economy);
//    p1.askBillForLastRide();
//
    // ---> Register first driver account <--- //
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
//    d1.findOrder();
    Car c2("Ranault Almeta", "yellow", "AV121E", CarType::comfortPlus);
    d1.registerCar(c2);
    d1.changeCurrentCar();
//    d1.findOrder();

//    p1.askBillForLastRide();

    p2.enter("123");
    a1.registerPassengerAccount(&p2);
    p2.enter("123");
    p2.makeOrder(Address("Univer Ulitsa, 1k2", Coordinates()), Address("Sport Ulitsa, 2k4", Coordinates()), CarType::comfortPlus);
    a1.enterPassenger("+7992");
    p2.makeOrder(Address("Univer Ulitsa, 1k2", Coordinates()), Address("Sport Ulitsa, 2k4", Coordinates()), CarType::comfortPlus);

    a1.findOrder("+7927");
    return 0;
}
