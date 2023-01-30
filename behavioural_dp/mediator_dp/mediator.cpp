#include "mediator.hpp"

int main()
{
    Mediator *mediator = new ConcreteMediator();

    User *c1 = new ConcreteUser( mediator, 1 );
    User *c2 = new ConcreteUser( mediator, 2 );
    User *c3 = new ConcreteUser( mediator, 3 );

    mediator->add( c1 );
    mediator->add( c2 );
    mediator->add( c3 );

    c1->send( "Hi!" );
    c3->send( "Hello!" );

    delete mediator;
    return 0;
}
