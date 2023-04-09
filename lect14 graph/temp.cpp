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
typedef vector<vector<int>> vvii ;

const ll largestLL= 1e18;
const int largestI = 1e9;
const ll primeInt2 = 1000000007;
const int primeInt = 998244353;

/*inbuilt functions:-
gcd :- __gcd(a,b)
to convert int to string to_string(number)
to convert char to int 
queue<int>, stack<int> --> has push() ,pop() , front() for queue ,top() for stack , 
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

void generate(vii &a , vvii &ans,int p){
    int n = a.size() ;
    if(p==n){
        bool flag = true ;
        for(int e=0 ;e<n;e++){
            if(e+1==a[e]){
                flag = false ;
            }
        }
        if(flag){
            ans.pb(a) ;
        }
        return ;
    }
    for(int e=p ;e<n ; e++){
        swap(a[e],a[p]) ;
        generate(a,ans,p+1) ;
        swap(a[e],a[p]) ;
    }
}

int main(){
    int n ;
    cin>>n ;
    vii a ;
    for(int e=0 ;e<n ; e++){
        a.pb(e+1) ;
    }
    //input is done 
    vvii ans ;
    generate(a,ans,0) ;
    for(int e=0 ;e<ans.size() ; e++){
        for(int p=0 ; p<ans[e].size() ; p++){
            cout<<ans[e][p]<<" ";
        }
        cout<<endl ;
    }
}