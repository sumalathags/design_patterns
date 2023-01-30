#include <iostream>
#include <map>
#include <string>
#include <memory>

using namespace std;

class Color {
public:
    virtual void addColor() = 0;
    virtual Color* clone() = 0;
};

class blueColor : public Color {
public:
    void addColor() {
        cout << "Blue color added" << endl;
    }
    Color* clone() {
        return new blueColor(*this);
    }
};

class blackColor : public Color {
public:
    void addColor() {
        cout << "Black color added" << endl;
    }
    Color* clone() {
        return new blackColor(*this);
    }
};

class ColorStore {
public:
    static Color* getColor(string colorName) {
        if (colorMap.find(colorName) == colorMap.end()) {
            if (colorName == "blue") {
                colorMap[colorName] = new blueColor();
            } else if (colorName == "black") {
                colorMap[colorName] = new blackColor();
            }
        }
        return colorMap[colorName]->clone();
    }
private:
    static map<string, Color*> colorMap;
};

map<string, Color*> ColorStore::colorMap;

int main() {
    ColorStore::getColor("blue")->addColor();
    ColorStore::getColor("black")->addColor();
    ColorStore::getColor("black")->addColor();
    ColorStore::getColor("blue")->addColor();
    return 0;
}