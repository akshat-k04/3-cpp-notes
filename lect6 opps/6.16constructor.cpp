 #include <bits/stdc++.h>
using namespace std ;

class Complex{
    int a,b ;
    public : 
    // creating a constructor
    // constructor is a special member function with the same name as of the class.
    // it is autometically invoked whenever an object is created
    // it is used to initialize the object of its class 
    
    Complex(void);
    void print(){
        cout<<a<<"+i"<<b <<endl ;
    }
};

Complex :: Complex(void){
   a= 10 ;
   b=5 ; 
}

int main(){
    Complex p ;
    p.print();
}



// constructor which does not take any parameter is called default constructor 
//the above code is example of default constructor 

/* ******** characterstics of constructor********

1.It should be declared in the public section of the class
2.they are autometically invoked whenever the object is created
3.Do not have return values and do not have return type (not even void)
4.it can have default arguments.(as we write a=10 , b=5)
*/











/*       *********difference bw parameters and arguments************


// Mult: Function definition
// a and b are the parameters
int Mult(int a, int b)
{
    // returning the multiplication
    return a * b;
}
 
// Driver code
int main()
{
    int num1 = 10, num2 = 20, res;
 
    // Mult() is called with
    // num1 & num2 as ARGUMENTS.
    res = Mult(num1, num2);
 
    // Displaying the result
    cout << "The multiplication is " << res;
    return 0;
}


*/