#include "WendexTaxi.h"

Passenger p1("Artem Chernitsa", "+7123", "Sosiska123");
Passenger p2("Ivan Razbil", "+7992", "PekaPeka");
Driver d1("Seva Mikulik", "+7927", "Krendel333");
Admin a1("Artem Murashko", "+7534", "Qeqeq");

Car c1("Ranault Logan", "yellow", "AV122E", CarType::economy);
Car c2("Ranault Almeta", "yellow", "AV121E", CarType::comfortPlus);

//p1.pinAddress(Address("Egoriev Proezd", Coordinates()));
//p1.makeOrder(Address("Ulitsa Lenina", Coordinates()), Address("Prospect Izmailovo", Coordinates()), CarType::economy);
using namespace std;
int main() {
    /* ---> Register first admin and make actions with him  <--- */
    a1.enter("Qeqeq"); // Admin with such number does not exist!
    a1.registerAccount(); // Admin successfully registered.
    a1.registerAccount(); // Admin is already registered!
    a1.enter("IncorrectPassword1"); // Incorrect password! Try again.
    a1.enter("Qeqeq"); // Admin successfully entered.
    a1.enter("Qeqeq"); //Admins is already login!

    /* ---> Register first passenger account and make actions with him <--- */
    p1.enter("IncorrectPassword1"); // Passenger with such number does not exist <-> Since p1 not registered yet
    p1.registerAccount(); // p1 successfully registered.
    p1.enter("IncorrectPassword1"); // Incorrect password!
    p1.enter("Sosiska123"); // Passenger successfully entered. (Correct password)
    p1.registerAccount(); // Passenger is already registered!
    p1.pinAddress(Address("Egoriev Proezd", Coordinates()));
    p1.makeOrder(Address("Ulitsa Lenina", Coordinates()), Address("Prospect Izmailovo", Coordinates()), CarType::economy); // Here, Mike, you should choose


    /* ---> Register first driver account and actions with him <--- */
    d1.enter("IncorrectPassword1"); // Driver with such number does not exist!
    d1.registerAccount(); // Driver successfully registered.
    d1.enter("qwerty"); // Incorrect password! Try again.
    d1.exit(); // Driver is not logged in!
    d1.findOrder(); // Driver is not logged in!
    d1.enter("Krendel333"); // Driver successfully entered.
    d1.findOrder(); // Can't do that, since driver account is not validated (first ride)

    a1.validateDriver("+7927"); // Driver successfully validated

    d1.findOrder(); // Driver has no cars! Please, register a car! BTW driver is validated
    d1.registerCar(c1); // Car successfully registered.
    d1.findOrder(); // Please, choose current car!
    d1.registerCar(c2); // Car successfully registered.
    d1.changeCurrentCar(); // Here, Mike, you should choose
    d1.findOrder(); // Here, Mike, you should choose

    p1.askBillForLastRide(); // Printed bill

    /* ---> Demonstration of admin's power <--- */
    a1.exit(); // Admin successfully exited.
    a1.enter("Qeqeq"); // Admin successfully entered.
    p2.enter("123"); // Passenger with such number does not exist!
    a1.registerPassengerAccount(&p2); // Admin successfully registered p2
    p2.enter("123"); // Incorrect password (Maybe he forgot it)
    a1.enterPassenger("+7992"); // Admin login p2's account
    p2.enter("PekaPeka"); // Passenger already login
    a1.makeOrder("+7992", Address("Univer Ulitsa, 1k2", Coordinates()),
                 Address("Sport Ulitsa, 2k4", Coordinates()), CarType::comfortPlus); // Admin created order for user p2
    a1.findOrder("+7927"); // Here admin find order for driver d1 (CarType you can choose in the previous calls)

    return 0;
}
