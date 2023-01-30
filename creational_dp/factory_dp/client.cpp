#include<iostream>
#include"car.hpp"
#include"truck.hpp"

using namespace std;

int main()
{
    string vehicle_type;
    cin>>vehicle_type;
    Vehicle* vehicle;
    if(vehicle_type == "car")
    {
        vehicle = new Car;
    }
    else if(vehicle_type == "truck")
    {
         vehicle = new Truck;
    }
    vehicle->create_vehicle();
    return 0;
}