#include <iostream>
#include <vector>

class Subject
{
    int                     value;
    std::vector<class Observer*> views;

public:
    void attach(Observer* obs) { views.push_back(obs); }
    void setValue(int val)
    {
        value = val;
        notify();
    }
    int  getValue() { return value; }
    void notify();
};

class Observer
{
    Subject* model;
    int      number;

public:
    Observer(Subject* mod, int num)
    {
        model  = mod;
        number = num;
        model->attach(this); // Observers register themselves with the Subject
    }
    virtual void update() = 0;
    Subject*     getSubject() { return model; }
    int          getDivisor() { return number; }
};

void Subject::notify()
{
    for (int i = 0; i < views.size(); i++)
        views[i]->update();
}
class DivObserver : Observer
{
public:
    DivObserver(Subject* mod, int num)
        : Observer(mod, num)
    {
    }
    void update()
    {
        int v = getSubject()->getValue();
        int d = getDivisor();
        std::cout << v << "divided by " << d << "is " << v / d << std::endl;
    }
};
class ModObserver : Observer
{
public:
    ModObserver(Subject* mod, int num)
        : Observer(mod, num)
    {
    }
    void update()
    {
        int v = getSubject()->getValue();
        int d = getDivisor();
        std::cout << v << "mod by " << d << "is " << v % d << std::endl;
    }
};