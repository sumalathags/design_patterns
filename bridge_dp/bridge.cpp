#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Workshop {
public:
    virtual void work() = 0;
};

class Produce : public Workshop {
public:
    void work() {
        cout << "Produced";
    }
};

class Assemble : public Workshop {
public:
    void work() {
        cout << " And";
        cout << " Assembled.";
        cout<<endl;
    }
};

class Vehicle {
protected:
    Workshop *workShop1;
    Workshop *workShop2;
public:
    Vehicle(Workshop *workShop1, Workshop *workShop2) {
        this->workShop1 = workShop1;
        this->workShop2 = workShop2;
    }
    virtual void manufacture() = 0;
};

class Car : public Vehicle {
public:
    Car(Workshop *workShop1, Workshop *workShop2) : Vehicle(workShop1, workShop2) {}
    void manufacture() {
        cout << "Car ";
        workShop1->work();
        workShop2->work();
    }
};

class Bike : public Vehicle {
public:
    Bike(Workshop *workShop1, Workshop *workShop2) : Vehicle(workShop1, workShop2) {}
    void manufacture() {
        cout << "Bike ";
        workShop1->work();
        workShop2->work();
    }
};

int main() {
    Vehicle *vehicle1 = new Car(new Produce(), new Assemble());
    vehicle1->manufacture();
    Vehicle *vehicle2 = new Bike(new Produce(), new Assemble());
    vehicle2->manufacture();
    
    return 0;
}