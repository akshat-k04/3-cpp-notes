// tell weather a number is prime or not
// time complexity = O(sqrt(n)) 

#include <bits/stdc++.h>
using namespace std ;


//solution here 

bool isprime(ll n){ 
    if(n<=1){
        return false ;
    }
    else{
        for(ll e=2 ;e<sqrt(n);e++){
            if(n%i==0){
                return false ;
            } 
        }
        return true ;
    }
}

int main(){
    ll n ;
    cin>>n ;
    cout<<isprime(n) ;
}