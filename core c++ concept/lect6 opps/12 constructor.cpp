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
} ;

int main(){
    profile akshat(100) ; // this is how for parametric constructor we give argument
    cout<<akshat.age ;
}