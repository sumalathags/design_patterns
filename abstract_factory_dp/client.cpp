#include<iostream>
#include"oem_abstract_factory.hpp"
using namespace std;

int main()
{
    string oem ;
    cin >> oem ;

    IFactory* fact = OEMAbstractFactory::create_factory(oem);

    ICar* car_obj = fact->create_car();
    car_obj->configure_car();

    ITruck* truck_obj = fact->create_truck();
    truck_obj->configure_truck();

    delete truck_obj;
    delete car_obj;
    delete fact;
   
    return 0;
}