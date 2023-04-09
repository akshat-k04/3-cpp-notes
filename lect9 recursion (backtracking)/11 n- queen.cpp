//leetcode problem link:-https://leetcode.com/problems/n-queens/

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

void print(vector<vector<vector<char>>> &real ){
    for(int e=0 ;e<real.size() ; e++){
        for(int f=0 ;f<real[e].size(); f++){
            for(int g=0 ; g<real[e][f].size() ; g++){
                cout<<real[e][f][g] ;
            }
            cout<<endl ;
        }
        cout<<endl ;
    }
}

bool valid(int p, vii & store,int index){
    int n = store.size() ;
    if(store.size()==0){
        return true ;
    }
    else{
        for(int e=0 ;e<n ;e ++){
            int y = index-e ;
            int x =store[e]-p ;
            if(x==0){
                return false ;
            }
            if(abs(x)==abs(y)){
                return false ;
            }
        }
        return true ;
    }
}

void generate(int n,vii & store,vector<vii> &ans,int index  ){
    if(index==n){
        ans.pb(store) ;
        return ;
    }
    for(int e=0 ;e<n ;e++){
        // cout<<valid(e,store,index) ;
        // cout<<e<<" "<<index<<"D"<<valid(e,store,index)<<endl ;
        if(valid(e,store,index)){
            store.pb(e) ;
            generate(n,store,ans,index+1) ;
            store.pob() ;
        }
    }
}

int main(){
    int n ;
    cin>>n ;
    vector<vii> ans ;
    vii temp ;
    generate(n,temp,ans,0) ;
    vector<vector<vector<char>>>real ;
    vector<vector<char>> temper ;
    vector<char> linear ;
    for(int e=0 ;e<ans.size() ; e++){
        for(int f=0 ;f<ans[e].size(); f++){
            for(int g =0 ; g<ans[e].size();g++){
                if(g==ans[e][f]){
                    linear.pb('Q') ;
                }
                else{
                    linear.pb('.') ;
                }
            }
            temper.pb(linear) ;
            linear.clear() ;
        }
        real.pb(temper) ;
        temper.clear() ;
    }
    print(real) ;
}