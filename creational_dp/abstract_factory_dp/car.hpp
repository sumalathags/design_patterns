#ifndef CAR_HPP
#define CAR_HPP

class ICar {
    public:
       virtual void configure_car()=0; 

};

class TataCar: public ICar{
    public:
        void configure_car();
};

class BenzCar: public ICar{
    public:
        void configure_car();
};

#endif