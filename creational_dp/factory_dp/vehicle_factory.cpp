# include "vehicle_factory.hpp"

Vehicle* VehicleFactory::get_vehicle(string vehicle_type)
{
    Vehicle* vehicle;
    if(vehicle_type == "car")
    {
        vehicle = new Car;
    }
    else if(vehicle_type == "truck")
    {
         vehicle = new Truck;
    }
    return vehicle;

}