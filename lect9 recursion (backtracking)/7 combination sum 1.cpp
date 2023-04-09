//leet code combination sum link:-https://leetcode.com/problems/combination-sum/

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

vector<vii> ans ;
int summer  ;
void generate(vii &a , vii & temp,int num,int sum){
    if(num==a.size()){
        if(sum==summer){
            ans.pb(temp) ;
        }
        return ;
    }
    generate(a,temp,num+1 ,sum) ; 
    int temmper= sum ;
    while(sum<summer){
       temp.pb(a[num]) ;
       sum+= a[num] ;
       generate(a,temp,num+1 ,sum) ; 
    }
    while(sum!=temmper){
       temp.pob() ;
       sum-= a[num] ;
    }
    
}

int main(){
    int n ;
    cin>>n ;
    cin>>summer ;
    vii a ;
    for(int r=0 ;r<n ;r++){
        int h ;
        cin>>h ;
        a.pb(h) ;
    }
    vii temp ;
    generate(a,temp,0,0) ;

    for(int e=0 ;e<ans.size(); e++){
        for(int f=0 ;f<ans[e].size() ; f++){
            cout<<ans[e][f]<<" " ;
        }
        cout<<endl ;
    }
}