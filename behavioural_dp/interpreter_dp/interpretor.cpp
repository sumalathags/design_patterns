#include "interpreter.hpp"

// evaluate a simple expression: 1 + 2.
// It creates a Context object, pushes two NumberExpression objects with the values 1 and 2 onto the context, 
// creates an AdditionExpression object with the two numbers as operands, pushes the result onto the context, 
// and finally pops the result from the context and prints it.
int main()
{
    Context context;
    context.push(new NumberExpression(1));
    context.push(new NumberExpression(2));
    context.push(new AdditionExpression(context.pop(), context.pop()));

    int result = context.pop()->interpret();
    std::cout << "Result: " << result << std::endl;

    return 0;
}
