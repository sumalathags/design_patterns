#include <iostream>
#include <unordered_map>

// Intrinsic state class
class Shape
{
public:
    virtual void draw() = 0;
};

// Concrete Flyweight class
class Circle : public Shape
{
private:
    std::string m_color;
    int         m_x, m_y, m_radius;

public:
    Circle(const std::string& color)
        : m_color(color)
    {
    }

    void setX(int x) { m_x = x; }
    void setY(int y) { m_y = y; }
    void setRadius(int radius) { m_radius = radius; }

    void draw()
    {
        if (m_color == "Blue")
        {
            std::cout << "\033[1;34m"
                      << "Drawing Circle[x:" << m_x << ", y:" << m_y << ", radius:" << m_radius << "]"
                      << "\033[0m" << std::endl;
        }
        else if (m_color == "Red")
        {
            std::cout << "\033[1;31m"
                      << "Drawing Circle[x:" << m_x << ", y:" << m_y << ", radius:" << m_radius << "]"
                      << "\033[0m" << std::endl;
        }
        else if (m_color == "Yellow")
        {
            std::cout << "\033[1;33m"
                      << "Drawing Circle[x:" << m_x << ", y:" << m_y << ", radius:" << m_radius << "]"
                      << "\033[0m" << std::endl;
        }
        else 
        {
            std::cout << "Drawing Circle[color:" << m_color << ", x:" << m_x << ", y:" << m_y << ", radius:" << m_radius << "]" << std::endl;
        }
    }
};

// Flyweight factory
class ShapeFactory
{
private:
    std::unordered_map<std::string, Circle*> m_circleMap;

public:
    Circle* getCircle(const std::string& color)
    {
        Circle* circle = m_circleMap[color];
        if (circle == nullptr)
        {
            circle             = new Circle(color);
            m_circleMap[color] = circle;
            std::cout << "Creating circle of color : " << color << std::endl;
        }
        return circle;
    }
};
