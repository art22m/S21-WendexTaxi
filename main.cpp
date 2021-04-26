#include "WendexTaxi.h"

using namespace std;
int main() {
    Passenger p1("Artem Chernitsa", "+7123", "Sosiska123", 5);
    p1.enter("Sos");
    p1.registerAccount();
    p1.enter("SOs");
    p1.enter("Sosiska123");
//    p1.registerAccount();
//    p1.exit();
//    p1.exit();
    p1.makeOrder(Address("Ulitsa Lenina", Coordinates()), Address("Prospect Izmailovo", Coordinates()), CarType::economy);

    return 0;
}
