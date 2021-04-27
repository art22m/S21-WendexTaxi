## Wendex Taxi

Programming Software System Course  

Homework 4 , 5

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
- Implement an AdminGateway. The same sense as in the previous task for the Passenger and Driver.
- Admin can login, see all information and block some functions for users.
  For example, he can block the possibility to order the ride for the passenger, or accept the ride for the driver. If the user calls the function that was blocked - an appropriate error should be thrown.
- Database. Use any. The simplest way - just a ﬁle. But you should not miss any data from launch to launch.
- A passenger can have multiple mobile devices, support correct work for all of them at once.
- A Driver can have multiple cars.
- A Car should be validated by admin before the ﬁrst ride.
-  Show work of the system in the main function.
-  If something was not mentioned - it means on your choice.
- All common requirements from previous tasks (readme, readability, extensibility, DRY, OOP etc).



#### *Main idea*

I have a class database where I store all users. You can also upload and download data here. The server class knows nothing about the lower-level classes (e.g. Gateway, Server, Users classes). Requests to this Database are made only from the Server class. The server class acts as a server (surprisingly =D). All user requests/actions come to the server, where they are processed. But for the request to get to the server, it must go through the gateway class. In the gateway class, I have a check, for example, whether the user is logged in, registered, and so on. There are also user classes in which the gateway methods are called. 

All in all, the methods of the user class call the methods of the gateway class, the methods of the gateway call the methods of the server, and the methods of the server call the methods of the database.

There are also other classes, such as the order class or the address class, but they are very simple to implement and are not required in the view.



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

