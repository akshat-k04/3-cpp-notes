 #include <bits/stdc++.h>
using namespace std ;

class number ;

class calculator{
    public :
    void addition(number, number);
    void subtraction(number, number);
    void multiplication(number, number);
};


class number{
    int a,b;
    public:
    friend class calculator ;
     void makeComplex(int c,int d){
        a=c ;
        b=d ;
     }
     void getComplex(){
        cout<<a<<"+i"<<b<<endl ;
     }
};


void calculator:: addition(number n, number m ){
    number ans ;
    ans.a =n.a+m.a ;
    ans.b = n.b + m.b ;
    // or we can write ans.makeComplex(n.a+m.a,n.b + m.b);
    ans.getComplex() ;
}
void calculator::subtraction(number n, number m ){
    number ans ;
    ans.a =n.a-m.a ;
    ans.b = n.b - m.b ;
    // or we can write ans.makeComplex(n.a+m.a,n.b + m.b);
    ans.getComplex() ;
}
void calculator:: multiplication(number n, number m ){
    number ans ;
    ans.a =n.a*m.a -n.b *m.b ;
    ans.b = n.a*m.b + n.b *m.a ;
    // or we can write ans.makeComplex(n.a+m.a,n.b + m.b);
    ans.getComplex() ;
}


int main(){
    number a,b ;
    a.makeComplex(1,2);
    b.makeComplex(3,4);

    calculator calculator ;
    calculator.addition(a,b);
    calculator.subtraction(a,b);
    calculator.multiplication(a,b);
}