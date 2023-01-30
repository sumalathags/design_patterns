#include <iostream>
#include <string>

// Builder interface with methods for setting different parts of a complex object
class Builder
{
public:
    virtual ~Builder()                        = default;
    virtual void setPartA(const std::string&) = 0;
    virtual void setPartB(const std::string&) = 0;
    virtual void setPartC(const std::string&) = 0;
};

// ConcreteBuilder class implements the Builder interface and builds the final object by concatenating the strings of its parts
class ConcreteBuilder : public Builder
{
public:
    void setPartA(const std::string& value) override { partA_ = value; }
    void setPartB(const std::string& value) override { partB_ = value; }
    void setPartC(const std::string& value) override { partC_ = value; }

    std::string getResult() { return partA_ + "-" + partB_ + "-" + partC_; }

private:
    std::string partA_, partB_, partC_;
};

// Director class uses the builder to create the final object
class Director
{
public:
    Director(Builder& builder)
        : builder_(builder)
    {
    }

    void build()
    {
        builder_.setPartA("A");
        builder_.setPartB("B");
        builder_.setPartC("C");
    }

private:
    Builder& builder_;
};
