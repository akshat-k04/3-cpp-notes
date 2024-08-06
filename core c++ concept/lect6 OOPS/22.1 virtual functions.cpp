/*
Overriding Base Class Behavior: When you have a base class and multiple derived classes, 
you might want to customize the behavior of certain functions in each derived class. By 
making these functions virtual in the base class, you allow each derived class to provide 
its own implementation. This promotes code reuse while allowing customization.
*/
#include <iostream>
using namespace std ;
class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing a shape." << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

int main() {
    Shape* shapePtr = new Circle();
    shapePtr->draw();  // Calls the draw() function of the Circle class

    delete shapePtr;
    return 0;
}

/*
output:-
Drawing a circle.
*/
