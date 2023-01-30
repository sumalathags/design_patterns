#include "builder.hpp"

// an instance of ConcreteBuilder is created and then used to build the final object with the help of the Director class
int main()
{
    ConcreteBuilder builder;
    Director        director(builder);
    director.build();
    std::cout << builder.getResult() << std::endl;

    return 0;
}
