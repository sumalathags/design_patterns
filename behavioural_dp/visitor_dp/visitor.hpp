#include <iostream>

class Stock
{
public:
    virtual void accept(class Visitor*) = 0;
};

class Apple : public Stock
{
public:
    void accept(Visitor*);
    void buy() { std::cout << "Apple::buy\n"; }
    void sell() { std::cout << "Apple::sell\n"; }
};
class Google : public Stock
{
public:
    void accept(Visitor*);
    void buy() { std::cout << "Google::buy\n"; }

    void sell() { std::cout << "Google::sell\n"; }
};

class Visitor
{
public:
    virtual void visit(Apple*)  = 0;
    virtual void visit(Google*) = 0;
    // private:
    static int m_num_apple, m_num_google;
    void       total_stocks() { std::cout << "m_num_apple " << m_num_apple << ", m_num_google " << m_num_google << '\n'; }
};
int Visitor::m_num_apple  = 0;
int Visitor::m_num_google = 0;
class BuyVisitor : public Visitor
{
public:
    BuyVisitor() { m_num_apple = m_num_google = 0; }
    void visit(Apple* r)
    {
        ++m_num_apple;
        r->buy();
        std::cout << "m_num_apple " << m_num_apple << std::endl;
    }
    void visit(Google* b)
    {
        ++m_num_google;
        b->buy();
        std::cout << " m_num_google " << m_num_google << '\n';
    }
};

class SellVisitor : public Visitor
{
public:
    void visit(Apple* a)
    {
        --m_num_apple;
        a->sell();
        std::cout << "m_num_apple " << m_num_apple << std::endl;
    }
    void visit(Google* g)
    {
        --m_num_google;
        g->sell();
        std::cout << "m_num_google " << m_num_google << std::endl;
    }
};

void Apple::accept(Visitor* v) { v->visit(this); }

void Google::accept(Visitor* v) { v->visit(this); }
