/*
here we find the no. of co-prime integers in O(1) 
after the sieve is made which take time O(n logn logn) 


approch of making sieve :- if number is prime then for all its multiple multiply with (p-1) and divide with p 


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

//solution here 
vii sieve(1000005) ;
void createsieve(){
    for(int e=0 ;e<1000002 ;e++){
        sieve[e]=e ;
    }
    for(int e=2 ; e<1000002;e++){
        if(sieve[e]==e){ //means it is prime
            sieve[e] = e-1 ;
            for(int f=2*e ;f<1000002;f+=e){
                sieve[f]/=e ;
                sieve[f]*=(e-1) ;
            }
        }
    }
}

int main(){
    createsieve() ;
    int n ;
    cin>>n ;
    cout<<sieve[n]<<endl ;
}