// Without override:
// If you don't use the override keyword, the compiler will still allow you to provide a 
// method in the derived class with the same name and parameter list as a virtual method in 
// the base class. The compiler might consider it as an attempt to override the base class 
// method, but it won't give you any explicit error if the method signatures match.

// Mistakenly New Method:
// If you mistakenly change the parameter list or method name slightly, the compiler will not 
// recognize it as an override. Instead, you'll end up creating a new method in the derived 
// class, which is not what you intended. This can lead to unexpected behavior in your program.


class Animal {
public:
    virtual void makeSound() {
        std::cout << "Animal makes a generic sound." << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override { // it will be ok if you not write override but
    // there is a problem occour when you accedently make parameter in this method then compiler will make it new method as you read in top of the page
        std::cout << "Dog barks." << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Cat meows." << std::endl;
    }
};

int main() {
    Animal* animalPtr;

    Dog dog;
    Cat cat;

    animalPtr = &dog;
    animalPtr->makeSound();  // Calls Dog's overridden method: "Dog barks."

    animalPtr = &cat;
    animalPtr->makeSound();  // Calls Cat's overridden method: "Cat meows."

    return 0;
}
