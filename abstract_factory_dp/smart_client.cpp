#include <iostream>
using namespace std;

class ICar {
    public:
       virtual void configure_car()=0; 

};

class TataCar: public ICar{
    public:
        void configure_car()
        {
            cout << "Configuring Tata Car" << endl;
        }
};

class BenzCar: public ICar{
    public:
        void configure_car()
        {
            cout << "Configuring Benz Car" << endl;
        }
};

class ITruck {
    public:
       virtual void configure_truck()=0; 

};

class TataTruck: public ITruck{
    public:
        void configure_truck()
        {
            cout << "Configuring Tata Truck" << endl;
        }
};

class BenzTruck: public ITruck{
    public:
        void configure_truck()
        {
            cout << "Configuring Benz Truck" << endl;
        }
};


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


class OEMAbstractFactory{
    public:
        static IFactory* create_factory(string& oem)
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

int main()
{
    string oem ;
    cin >> oem ;

    IFactory* fact = OEMAbstractFactory::create_factory(oem);

    ICar* car_obj = fact->create_car();
    car_obj->configure_car();

    ITruck* truck_obj = fact->create_truck();
    truck_obj->configure_truck();    

    delete fact;
    delete car_obj;
    delete truck_obj;
    
   
    return 0;
}