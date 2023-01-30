#ifndef TRUCK_HPP
#define TRUCK_HPP

class ITruck {
    public:
       virtual void configure_truck()=0; 

};

class TataTruck: public ITruck{
    public:
        void configure_truck();
};

class BenzTruck: public ITruck{
    public:
        void configure_truck();
};

#endif