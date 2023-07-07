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

vll factorial(100005) ;

void createFactorial(){
    factorial[0]=1 ;
    for(int e=1 ;e<100003 ;e++){
        factorial[e] = (factorial[e-1]*e)  % 1000000007;
    }
}

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


ll combination(int n,int r){
    ll ans = factorial[n] ;
    ll deno = factorial[n-r] * factorial[r] % 1000000007 ;
    ans = (ans* modularInverse(deno,1000000007))  % 1000000007 ;
}

int main(){
    int n,r ;
    cin>>n>>r ;
    createFactorial() ;
    cout<<combination(n,r)<< " " ;
    
}