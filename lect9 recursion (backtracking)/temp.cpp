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

const ll largestLL= 1e18;
const int largestI = 1e9;
const ll primeInt2 = 1000000007;
const int primeInt = 998244353;

/*inbuilt functions:-
gcd :- __gcd(a,b)
to convert int to string to_string(number)
to convert char to int we have to handle it mannually int a = '6' - '0' 
queue<int>, stack<int> --> has push() ,pop() , front() for queue ,top() for stack , 
reverse(a.begin() , a.end())
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


int main(){
    int n,k;
    cin>>n>>k ; //n=4 =9
    vii factorial ;
    int temp=1 ;
    for(int e=1 ; e<n ; e++){
        temp*=e ;
        factorial.pb(temp) ; //1
    }
    vii ans ; //
    vii store ; //
    for(int e=0 ;e<n ; e++){
        store.pb(e+1) ; // 1 2 3 4
    }
    while(factorial.size()>0){
        int h = (k-1) /factorial[factorial.size()-1] ; //0 1 1 1
        ans.pb(store[h]) ; // 1 3 4 5
        store.erase(store.begin()+h) ; //2 3 4 5   2 4 5  2 5  2
        k-= h*factorial[factorial.size()-1] ; // 10  4  2 1
        factorial.pob(); // 1 2 6   1 2  1 null
    }

    for(int e=0 ;e<store.size(); e++){
        ans.pb(store[e]) ;
    }

    for(int e=0 ;e<ans.size() ;e ++){
        cout<<ans[e] ;
    }
    cout<<endl ;
}