#include "state.hpp"

int main()
{
    AlertStateContext stateContext;
    stateContext.alert();
    stateContext.alert();
    stateContext.setState(new Silent());
    stateContext.alert();
    stateContext.alert();
    stateContext.setState(new Vibration());
    stateContext.alert();

    return 0;
}