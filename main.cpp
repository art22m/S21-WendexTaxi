#include <iostream>
#include <vector>
#include "WendexTaxi.h"

using namespace std;

/* ----- Cars ----- */
Economy car1("Ranault Logan", Coordinates(), CarColor::red, "AB123C");
Economy car2("Lada Granta", Coordinates(), CarColor::yellow, "AK133E");
Comfort car3("Kia Rio", Coordinates(), CarColor::white, "EA873M");
Comfort car4("Hyondai Solaris", Coordinates(), CarColor::black, "EA823M");
ComfortPlus car5("Kia Cerato", Coordinates(), CarColor::black, "MJ122J");
Business car6("Kia Optima", Coordinates(), CarColor::black, "EK222X");

/* ----- Drivers ----- */
vector <Driver> drivers = {
        Driver("Artem", 4.5, "+123", &car1),
        Driver("John", 2.7, "+231", &car3),
        Driver("Alex", 3.8, "+443", &car5),
        Driver("Ivan", 4.2, "+777", &car6),
};

/* ----- Passengers ----- */
vector <Passenger> passengers = {
        Passenger("Alena", 4.92, "+898"),
        Passenger("Katya", 4.8, "+897"),
        Passenger("Vsevolod", 4.98, "+896"),
        Passenger("Sergey", 4.9, "+895"),
};

/* ----- Gateways ----- */
DriverGateway driverGateway;
PassengerGateway passengerGateway;

using namespace std;

int main() {
    driverGateway.setOnlineStatus(drivers[0], true); // Set status of driver number 1 to online
    driverGateway.setOnlineStatus(drivers[1], true); // Set status of driver number 2 to online
    driverGateway.setOnlineStatus(drivers[2], true); // Set status of driver number 3 to online
    driverGateway.setOnlineStatus(drivers[3], true); // Set status of driver number 4 to online

    driverGateway.checkAvailableOrders();

    /*
     * Passenger Katya create order with type economy.
     * Since Artem has car economy, he took it.
    */
    passengerGateway.createOrder(passengers[1], Address("Moscow, RedSquare", Coordinates()), Address("Moscow, MoscowCity", Coordinates()), CarType::economy);


    driverGateway.setOnlineStatus(drivers[3], false); // Set status of driver number 4 to offline
    passengerGateway.createOrder(passengers[2], Address("Moscow, RedSquare", Coordinates()), Address("Moscow, MoscowCity", Coordinates()), CarType::business);

    driverGateway.setOnlineStatus(drivers[3], true);
    driverGateway.findOrder(drivers[3]);

    return 0;
}
