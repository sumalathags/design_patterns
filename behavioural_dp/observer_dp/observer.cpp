#include "observer.hpp"

int main()
{
    Subject     sub;
    DivObserver a(&sub, 4);
    DivObserver b(&sub, 3);
    ModObserver c(&sub, 10);
    sub.setValue(99);
    std::cout << "hello==========" << std::endl;
    sub.setValue(21);
    return 0;
}