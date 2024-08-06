#include <bits/stdc++.h> 
using namespace std ;

class profile{
private:
    int money ;
    int phone ;

public:
    string surname ;
    int age ;
    profile(){} // default constructor
    profile(int k){
        money=k ;
        phone = 000000000 ;
        age=0 ;
    }
} ;

int main(){
    profile akshat(100) ; // this is how for parametric constructor we give argument
    cout<<akshat.age ;
    profile garvit ; 
    //********** note:- if you comment thw default constructor then it will give you error
    // if you make a constructor you also have to make a default constructor also to not meet with error
}