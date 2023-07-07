//it is based on euclid division lemma
// gcd of 0,any number is that number it is very logical 
//NOTE: it is very obvious to say that gcd(a,b)= gcd(a-b ,b) = gcd(a,b-a) 
//let we have to find the hcf of 30,12
/*
30=12*2+6 
12=6*2+0 
so , 6 is the hcf

eg2:-
140,12
140 = 12*11+8
12=8*1+4
8=4*2+0
so 4 is the HCF
*/


#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define pob pop_back
//#define fir first 
//#define sec second
#define all(x) x.begin(), x.end()


//solution here 

int gcd(int a,int b){
    if(b==0){
        return a ;
    }
    else{
        return gcd(b,a%b) ;
    }
}

int main(){
    int a,b ;
    cin>>a>>b ;
    cout<<gcd(max(a,b),min(a,b)) ;
}