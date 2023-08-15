#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define pob pop_back
#define fir first 
#define sec second
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vii;
typedef vector<vector<int>> vvii;

void print(vii& a){int n = a.size() ;for(int e=0 ;e<n ;e++)cout<<a[e] <<' ';cout<<endl ;}

ll binpow(ll a, ll b) { 
    //b=m-2 ;// if want to find the modular inverse 
    ll res =1 ;
    for(int e= 0;e<63 ;e++){
        res*=(1LL*2) ;
        cout<<res<<endl ;
    }
    return res;
}


int main(){
    cout<<binpow(1LL*2,63) ;
    ll a = 	9223372036854775808 ;
    cout<<a ;
}