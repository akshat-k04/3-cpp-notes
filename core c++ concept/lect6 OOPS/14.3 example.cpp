#include <iostream>

class Base {
public:
    int a;
};

class Derived : public Base {
public:
    int a;
};

int main() {
    Derived d;
    d.a = 5;  // This sets the 'a' variable in the Derived class to 5
    std::cout << "Derived 'a': " << d.a << std::endl;  // Output: Derived 'a': 5

    Base b;
    b.a = 10;  // This sets the 'a' variable in the Base class to 10
    std::cout << "Base 'a': " << b.a << std::endl;  // Output: Base 'a': 10

    return 0;
}
