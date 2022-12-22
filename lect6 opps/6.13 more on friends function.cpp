 #include <bits/stdc++.h>
using namespace std ;

class cmplex {
    private: 
    int a;
    int b;
    public: 
    void setNum () ;
    void getNum () ;
    friend cmplex num(cmplex , cmplex ) ;
};
// the basic difference bw member function and friend function is that member function run for perticular object 
// while friend function is normal our function 
void cmplex :: setNum(){
    a= 5 ;
    b=6 ;
}
void cmplex :: getNum(){
    cout<<a<<"+i"<<b<<endl ;
}

cmplex num (cmplex m , cmplex n){
    cmplex p ;
    p.a=9 ;
    p.b=0;
    return p ;
}

int main(){
    cmplex x,y ;
    x.setNum() ;
    y.setNum() ;
    cmplex z = num(x,y) ;
    z.getNum() ;
}