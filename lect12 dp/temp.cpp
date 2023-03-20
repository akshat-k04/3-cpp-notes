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


int main(){
    int t ;
    cin>>t ;
    for(int r=0 ;r<t ;r++){
        int n ,k ;
        cin>>n>>k ;
        vpii a ;
        pair<int,int> base ={-1,-1} ;
        for(int e=0 ;e<n ;e++){
            int p,q ;
            cin>>p>>q ;
            if(q>= k  && p<= k) {
                a.pb({p,q}) ;
                if(base.first==-1){
                    base.first= p ;
                    base.second = q ;
                }
                else {
                    if(base.second-base.first> q-p){
                        base.first= p ;
                        base.second=q ;
                    }
                }
            }
        }
        // we made a vector in all the pair has k 
        if(a.size()==0){
            cout<<"NO"<<endl ;
        }
        else{
            // we have base array 
            vii number ;
            for(int e=base.first ; e<= base.second ; e++){
                if(e==k){
                    continue ;
                }
                number.pb(e) ;
            }
            // we have numbers
            n= a.size() ;
            bool possible = true ;
            for(int e=0 ;e<number.size() ; e++){
                for(int hj = 0; hj<n ;hj++){
                    if(a[hj].first>number[e] || a[hj].second<number[e]){
                        break ;
                    }
                    if(hj==n-1){
                        possible = false ;
                        goto kl ;
                    }
                }
            }
            kl :;
            if(possible){
                cout<<"YES"<<endl ;
            }
            else{
                cout<<"NO"<<endl ;
            }
        }

    }
}