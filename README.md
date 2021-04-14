## Wendex Taxi

Programming Software System Course  

Homework 4  

TA: https://github.com/l1va  



#### *Requirements:*

- Implement two gateways. Passengers (passengers mobile app) should communicate with the system only through PassengerGateway class. Drivers (drivers mobile app) should communicate with the system only through DriverGateway class.

- A Passenger has name, rating, order history, payment methods, pinned addresses. He can
  - login, see order history, see and update payment methods, see and update pinned addresses.
  - select any two addresses (from, to) and carType to check the time and price of the ride. There are 4 car types: Economy, Comfort, ComfortPlus, Business.
  - order the ride if he agree with conditions (there is possibility to change default payment method for this particular ride).
  - ask for the current coordinates of the car during the ride.
  - see the ride in the order history after the end of the ride and ask for the bill of that ride. 
-  A driver has name, rating, order history, one car, status(is working or not, in ride or not). He can login, see order history, see a car, update status, check available orders, accept or decline it.
- A Car has model, carType, current coordinates, the color and the number. If the type is Comfort it has count of freeBottleOfwater (it randomly decreases during rides). If the type is Business it has the method parkRightInFrontOfTheEntrance. The order has time and two addresses.
- Database. Use any. The simplest way - just a ﬁle. But you should not miss any data from launch to launch.
-  Show work of the system in the main function.
-  If something was not mentioned - it means on your choice.
- All common requirements from previous tasks (readme, readability, extensibility, DRY, OOP etc).



#### *Main idea*

I have a singleton class System in which I perform basic operations for finding orders, uploading online drivers, and so on.

I have two Gateways: PassengerGateway, through which I do all the operations of the passenger class and DriverGateway which is related to System class and Driver class and do their operations.

#### *Dependencies*

- C++ 14

- CMake 3.17

  

#### *How to run the code*

[1] Download source from GitHub

[2] Open terminal

[2] Type command to install gcc

[3] Go to that folder where you've download source

[4] Compile the program using the following command:

 **gcc main.cpp**

[5] To run the program type the following command

 **./a.out**

