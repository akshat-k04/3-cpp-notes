/*
   here we find the number of numbers that are co prime with the nunmber n and less than n


1. let we have function f(x)  this will give the ans
   so f(2) =1 ,f(3) =2 ,f(5)=4 ,f(7)=6,f(11) =10 
   all this numbers are prime so we can say that all number less then n are co prime with n


2. now , let x is prime
   so, f(x^n) = x^n - no. of numbers that are not co-prime
   let s take eg 3^4 => there are only 3^3 numbers that are not co-prime with 3^4 
   very logical
   so ,
   ------if x is prime the f(x^n) = x^n - x^(n-1) = (x^(n-1))(x-1)  -------

3. now we have 1 theorm that if f(x)  is arithematic function then
   f(m*n) = f(m)*f(n)  if n,m are coprime


4. we can write any function as n = A^a*B^b*C^c ... 
   where A,B,C... are prime
   so, f(n) = f(A^a)*f(B^b)*f(C^c)....
   f(n) = (n/A*B*C..)*(A-1)(B-1)(C-1)...
   this is the formula 
*/
#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define pob pop_back
//#define fir first 
//#define sec second
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vii;
typedef vector<vector<int>> vvii;



//solution here 


vpii primefactors ;

void primefact(int n){
    for(int e=2 ;e<=sqrt(n);e++){
        if(n%e==0){
            primefactors.pb({e,0});
            while(n%e==0){
                n/=e ;
                primefactors[primefactors.size()-1].second++ ;
            }
        }
    }
    if(n!=1){
        primefactors.pb({n,1}) ;
    }

}


ll etf(int n){
    primefact(n) ;
    ll ans = n; 
    for(int e=0 ;e<primefactors.size();e++){
        ans*=(primefactors[e].first-1) ;
        ans/=primefactors[e].first ;
    }
    return ans ;
}


int main(){
    int n ;
    cin>>n ;
    cout<<etf(n)<<endl ;
}