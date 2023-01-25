## Vehicle Library With abstract Factory Design pattern
g++ -c car.cpp truck.cpp 
ar ru vehicle_factory_library.a car.o truck.o
g++ -o client_factory client_factory.cpp vehicle_factory_library.a 
./client_factory
Enter input: car or truck