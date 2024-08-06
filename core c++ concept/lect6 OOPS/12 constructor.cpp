#include <bits/stdc++.h> 
using namespace std ;

class profile{
private:
    int money ;
    int phone ;

public:
    string surname ;
    int age ;
    profile(int k){
        money=k ;
        phone = 000000000 ;
        age=0 ;
    }
    profile(){} // if we write the above consturctor then it is must that we have to write this default constructor
} ;

int main(){
    profile akshat(100) ; // this is how for parametric constructor we give argument
    cout<<akshat.age ;
    profile garvit  ;
}