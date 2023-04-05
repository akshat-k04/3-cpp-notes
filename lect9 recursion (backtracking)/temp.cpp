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

void dooperation( int ini ,int lst , vii & storage){
    storage[ini]++ ;
    storage[lst]-- ;
}

int main(){
    int t ;
    cin>>t ;
    for(int r=0 ;r<t ;r++){
        int n ,q ;
        cin>>n>>q ;
        vector<int> a(n) ;
        for(int e=0 ;e<n ;e++){
            cin>>a[e] ;
        }
 
        vector<vector<int>> query ;
        for(int e=0 ;e<q ; e++){
            vector<int> local ;
            int h ;
            cin>>h ;
            local.push_back(h) ;
            if(h==1){
                cin>>h ;
                local.push_back(h) ;
                cin>>h ;
                local.push_back(h) ;
            }
            else{
                cin>>h ;
                local.push_back(h) ;
            }  
            query.push_back(local) ;
        }
        vii ans ;
        vii storage(n+1,0) ;
        for(int e=0 ;e<q ;e++){
            if(query[e][0]==1){
                dooperation(query[e][1]-1,query[e][2],storage) ;
            }
            else {
                ans.push_back(a[query[e][1]-1]) ;
            }
        }
        for(int e=0 ;e<ans.size() ; e++){
            cout<<ans[e]<<endl ;
        }
    }
}