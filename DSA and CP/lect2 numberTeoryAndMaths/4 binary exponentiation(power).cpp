// find a^b
// compleaxity is O(log(n)) 

//approch
/*  eg:- 3^13
    res  num  pow
     1    3    13
     3    3    12
     3    9     6
     3    81    3
    3*81  81    2
    3*81  81*81 1
    print (3*81*81*81) ;   
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

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1){
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main(){
    int a,n ;
    cin>>a>>n ;
    cout<<binpow(a,n,1e+7);
}