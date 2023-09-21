/*
We can use constructors in derived classes in C++
1. If the base class constructor does not have any arguments, there is no need for any 
constructor in the derived class
2. But if there are one or more arguments in the base class constructor, derived class 
need to pass argument to the base class constructor
3. If both base and derived classes have constructors, base class constructor is executed 
first


Constructors in Multiple Inheritances
1. In multiple inheritances, base classes are constructed in the order in which they appear 
in the class deceleration. For example if there are three classes “A”, “B”, and “C”, and 
the class “C” is inheriting classes “A” and “B”. If the class “A” is written before class 
“B” then the constructor of class “A” will be executed first. But if the class “B” is 
written before class “A” then the constructor of class “B” will be executed first.

2. In multilevel inheritance, the constructors are executed in the order of inheritance. 
For example if there are three classes “A”, “B”, and “C”, and the class “B” is inheriting 
classes “A” and the class “C” is inheriting classes “B”. Then the constructor will run 
according to the order of inheritance such as the constructor of class “A” will be called 
first then the constructor of class “B” will be called and at the end constructor of class 
“C” will be called.
*/