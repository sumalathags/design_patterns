#ifndef VEHICLE_FACTORY_HPP
#define VEHICLE_FACTORY_HPP

#include<iostream>
#include"car.hpp"
#include"truck.hpp"
using namespace std;

class VehicleFactory {
    public:
        // it is declared as static because no need to create the object to call this function
        static Vehicle* get_vehicle(string vehicle_type);

};

#endif