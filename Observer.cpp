#include <iostream>
#include<vector>
using namespace std;

class Subject{
  int value;
  vector <class Observer* > views;
public:
    void attach(Observer *obs){
        views.push_back(obs);
    }
    void setValue(int val){
        value=val;
        notify();
    }
    int getValue(){
        return value;
    }
    void notify();
};

class Observer{
  Subject *model;
  int number;
public:
    Observer(Subject *mod, int num){
        model=mod;
        number=num;
        model->attach(this); // Observers register themselves with the Subject
    }
    virtual void update()=0;
    Subject* getSubject(){
        return model;
    }
    int getDivisor(){
        return number;
    }
};

void Subject::notify(){
    for(int i=0;i<views.size();i++)
        views[i]->update();
}
class DivObserver: Observer{
public:
    DivObserver(Subject * mod,int num):Observer(mod,num){}
    void update(){
        int v=getSubject()->getValue();
        int d=getDivisor();
        cout<<v<<"divided by "<<d<<"is "<<v/d<<endl;
    }
};
class ModObserver: Observer{
public:
    ModObserver(Subject * mod,int num):Observer(mod,num){}
    void update(){
        int v=getSubject()->getValue();
        int d=getDivisor();
        cout<<v<<"mod by "<<d<<"is "<<v%d<<endl;
    }
};
int main(){
    Subject sub;
    DivObserver a(&sub,4);
    DivObserver b(&sub,3);
    ModObserver c(&sub,10);
    sub.setValue(99);
    cout<<"hello=========="<<endl;
    sub.setValue(21);
    return 0;
}