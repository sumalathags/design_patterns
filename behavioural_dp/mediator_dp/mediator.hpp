#include <iostream>
#include <string>
#include <vector>

class Mediator;

/*
 * User classes
 * each User communicates with its mediator whenever
 * it would have otherwise communicated with another User
 */
class User
{
public:
    User(Mediator* const m, const unsigned int i)
        : mediator(m)
        , id(i)
    {
    }

    virtual ~User() {}

    unsigned int getID() { return id; }

    virtual void send(std::string)    = 0;
    virtual void receive(std::string) = 0;

protected:
    Mediator*    mediator;
    unsigned int id;
};

class ConcreteUser : public User
{
public:
    ConcreteUser(Mediator* const m, const unsigned int i)
        : User(m, i)
    {
    }

    ~ConcreteUser() {}

    void send(std::string msg);

    void receive(std::string msg) { std::cout << "Message '" << msg << "' received by User " << id << std::endl; }
};

/*
 * Mediator
 * defines an interface for communicating with User objects
 */
class Mediator
{
public:
    virtual ~Mediator() {}

    virtual void add(User* const c)                              = 0;
    virtual void distribute(User* const sender, std::string msg) = 0; // distribute msg to other objects

protected:
    Mediator() {}
};

/*
 * Concrete Mediator
 * implements cooperative behavior by coordinating User objects
 * and knows its Users
 */
class ConcreteMediator : public Mediator
{
public:
    ~ConcreteMediator()
    {
        for (unsigned int i = 0; i < users.size(); i++)
        {
            delete users[i];
        }
        users.clear();
    }

    void add(User* const c) { users.push_back(c); }

    void distribute(User* const sender, std::string msg)
    {
        for (unsigned int i = 0; i < users.size(); i++)
        {
            if (users.at(i)->getID() != sender->getID())
            {
                users.at(i)->receive(msg);
            }
        }
    }

private:
    std::vector<User*> users;
};

void ConcreteUser::send(std::string msg)
{
    std::cout << "Message '" << msg << "' sent by User " << id << std::endl;
    mediator->distribute(this, msg);
}
