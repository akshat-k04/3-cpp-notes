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

void print(vii& a){int n = a.size() ;for(int e=0 ;e<n ;e++)cout<<a[e] <<' ';cout<<endl ;}

void fibonachii(int n,vii &store){
    store.pb(0) ;store.pb(1) ;
    for(int e=2 ;e<=n ;e++){
        store[e]=store[e-1] +store[e-2] ;
    }
}

int main(){
    vii store ;
    fibonachii(100000,store) ;
    int k ;cin>>k ;
    cout<<store[k+1] ;
}