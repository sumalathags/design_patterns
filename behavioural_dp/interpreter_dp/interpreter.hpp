#include <iostream>
#include <string>
#include <vector>

// Expression is an abstract base class that defines an interpret method.
class Expression
{
public:
    virtual int interpret() = 0;
};

// NumberExpression is a concrete subclass of Expression that represents a number in the expression. 
// The class holds an integer number_ and implements the interpret method to return this number.
class NumberExpression : public Expression
{
    int number_;

public:
    explicit NumberExpression(int number) : number_(number) {}

    int interpret() override { return number_; }
};

// AdditionExpression is another concrete subclass of Expression that represents the addition of two expressions. 
// The class holds two Expression pointers left_operand_ and right_operand_ 
// It implements the interpret method to return the sum of their interpret results.
class AdditionExpression : public Expression
{
    Expression *left_operand_;
    Expression *right_operand_;

public:
    AdditionExpression(Expression *left, Expression *right)
        : left_operand_(left), right_operand_(right) {}

    int interpret() override
    {
        return left_operand_->interpret() + right_operand_->interpret();
    }
};

// Context is a class that holds a list of Expression pointers, providing push and pop methods to add and remove expressions from the list.
class Context
{
    std::vector<Expression *> context_;

public:
    void push(Expression *expression) { context_.push_back(expression); }
    Expression *pop()
    {
        Expression *expression = context_.back();
        context_.pop_back();
        return expression;
    }
};
