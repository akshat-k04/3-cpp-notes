// time complexity of creating sieve = O(nloglogn) 
// finding the factors is O(log n) ;

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

//solution here 

void createsieve(vii & sieve){
    for(ll e=2 ;e<sieve.size();e++){
        if(sieve[e]==0){
            sieve[e]=e ;
            for(ll f=e*e ;f<sieve.size() ;f+=e){
                if(sieve[f]==0){
                    sieve[f]=e ;
                }
            }
        }
    }
}

void findfactor(int num,vii & sieve,vii &ans){
    while(num>1){
        ans.pb(sieve[num]) ;
        num/=sieve[num] ;
    }
}

int main(){
    vii sieve(10000005) ;
    createsieve(sieve) ;

    int num ;
    cin>>num ;
    // we have to find the prime factorization of a number num
    vii ans ;
    findfactor(num,sieve,ans) ;
    for(int e=0 ;e<ans.size() ;e++){
        cout<<ans[e]<< " " ;
    }
    // cout<<endl ;
}