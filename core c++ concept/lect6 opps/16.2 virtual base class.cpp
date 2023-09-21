/*
                              a
                             / \
                           b     c
                            \   /
                              d
                              when we make object of d then we get 2 times a that is ambiguity 
                              while making b,c write public virtual a 
                              the virtual keyword take care that a will only assign one time
                              

*/




#include <iostream> 
using namespace std; 
class A { 
public: 
    void say() 
    { 
        cout << "Hello world"<<endl; 
    } 
}; 
class B : public virtual A { 
};   
class C : public virtual A { 
};   
class D : public B, public C { 
}; 