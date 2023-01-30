#ifndef VEHICLE_FACTORY_HPP
#define VEHICLE_FACTORY_HPP

#include<iostream>
#include"car.hpp"
#include"truck.hpp"
using namespace std;

class IFactory {
    public:
       virtual ICar* create_car()=0;
       virtual ITruck* create_truck()=0;
       

};

class TataFactory: public IFactory {
    public:       
        TataCar* create_car()
        {
            return new TataCar();
        }
        TataTruck* create_truck()
        {
            return new TataTruck();
        }
     

};

class BenzFactory: public IFactory  {
    public:        
        BenzCar* create_car()
        {
            return new BenzCar();
        }
        BenzTruck* create_truck()
        {
            return new BenzTruck();
        }
      

};

#endif