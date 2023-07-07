// Given two values M and N, which represent a matrix[M][N]. We need to find the total unique paths from the top-left cell (matrix[0][0]) to the rightmost cell (matrix[M-1][N-1]).

// At any cell we are allowed to move in only two directions:- bottom and right.


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

const ll largestLL= 1e18;
const int largestI = 1e9;
const ll primeInt2 = 1000000007;
const int primeInt = 998244353;

/*inbuilt functions:-
gcd :- __gcd(a,b)
*/

//functions
//all prime till a
//vector<int> prime(100001,1) ;
//1 means prime
//void sieve(int a){
//    for(int e=2 ; e<=a ;e++){
//        if(prime[e]==1 &&e*e<=a){
//            for(int p=e*e ;p<=a ;p+=e){
//                 prime[p]=0 ;
//            }
//        }
//    }
//    for(int e=2  ; e<=a ;e++){
//        if(prime[e]==1){
//            cout<<e<<" ";
//        }
//    }
//}

//check prime (true means prime )
bool checkPrime(int a){
    int b = sqrt(a) ;
    for(int e=2 ; e<=b ;e++){
        if(a%b==0){
            return false ; // means it is not prime
        }
    }
    return true ;
}

//solution here 

void solve(int n,int m){
   vvii a ;
    
    for(int e=0 ;e<n ;e++){
        vii temp ;
        for(int f=0 ;f<m ;f++){
            if(e==0){
                temp.pb(1) ;
            }
            else{
                if(f==0){
                    temp.pb(1) ;
                }
                else{
                    temp.pb(temp[e][f-1]+temp[e-1][f]) ;
                }
            }
        }
        a.pb(temp) ;
    }
    cout<<a[n-1][m-1] <<endl ;
}

int main(){
    int t ;
    cin>> t ;
    for(int r=0 ;r<t ;r++){
        int n,m ;
        cin>>n>>m ;
        solve(n,m) ;
    }
}