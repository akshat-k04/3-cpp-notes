/*
farmets theorm:- if a,m are co-prime and m is prime then (a^(m-1))%m= 1 
    m must be prime and a must be co-prime with m

very logical
let if a%m = 2 
then a*a%m!=2 it can be 4 3 1 etc any thing but less then m
this same thin happen till lst and finally in lst we get 1

1. a^ (m-2),a both are modulo invers of each other as a^(m-1)%m ==1
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

ll modularInverse(ll a,ll mod){
    ll b = mod-2 ;
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main(){
    int a,m ;
    cin>>a>>m ;
    cout<<modularInverse(a,m) ;
}