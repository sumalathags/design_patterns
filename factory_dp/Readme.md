## Vehicle Library Without Factory Design pattern
g++ -c car.cpp truck.cpp
ar ru vehicle_library.a car.o truck.o
g++ -o client client.cpp vehicle_library.a 
./client
Enter input: car or truck

## Vehicle Library With Factory Design pattern
g++ -c vehicle_factory.cpp car.cpp truck.cpp 
ar ru vehicle_factory_library.a vehicle_factory.o car.o truck.o
g++ -o client_factory client_factory.cpp vehicle_factory_library.a 
./client_factory
Enter input: car or truck