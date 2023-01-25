#include"vehicle_factory.hpp"

class OEMAbstractFactory{
    public:
        static IFactory* create_factory(string oem)
        {
            if(oem == "TATA Motors")
            {
                return new TataFactory();
            }
            else if(oem == "Mercedes Benz")
            {
                return new BenzFactory();
            }
        }
     

};