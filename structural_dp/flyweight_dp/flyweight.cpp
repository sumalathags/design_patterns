#include "flyweight.hpp"

int main()
{
    ShapeFactory* shapeFactory = new ShapeFactory();

    Circle* circle1 = shapeFactory->getCircle("Red");
    circle1->setX(1);
    circle1->setY(2);
    circle1->setRadius(3);
    circle1->draw();

    Circle* circle2 = shapeFactory->getCircle("Red");
    circle2->setX(4);
    circle2->setY(5);
    circle2->setRadius(6);
    circle2->draw();

    Circle* circle3 = shapeFactory->getCircle("Red");
    circle3->setX(7);
    circle3->setY(8);
    circle3->setRadius(9);
    circle3->draw();

    Circle* circle4 = shapeFactory->getCircle("Blue");
    circle4->setX(1);
    circle4->setY(2);
    circle4->setRadius(3);
    circle4->draw();

    Circle* circle5 = shapeFactory->getCircle("Blue");
    circle5->setX(4);
    circle5->setY(5);
    circle5->setRadius(6);
    circle5->draw();
}
