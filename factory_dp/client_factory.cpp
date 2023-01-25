#include<iostream>
#include"car.hpp"
#include"truck.hpp"
#include"vehicle_factory.hpp"

using namespace std;

int main()
{
    string vehicle_type;
    cin>>vehicle_type;
    Vehicle* vehicle = VehicleFactory::get_vehicle(vehicle_type);  
    vehicle->create_vehicle();
    return 0;
}