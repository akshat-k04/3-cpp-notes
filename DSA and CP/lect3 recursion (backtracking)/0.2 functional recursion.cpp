// same q that return the sum of n natural numbers

#include <bits/stdc++.h>
using namespace std ;

int generate(int n){
    if(n==0){
        return 0 ;
    }
    return generate(n-1)+n ;
}

// here we don't use any para meter here the functionhas to return the sum 
int main(){
    int n ;
    cin>> n ;
    cout<< generate(n) ;
}