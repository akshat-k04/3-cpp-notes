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

void bintint(int n,vii &ans){
    int num = log2(n*1.0) ;
    for(int e=num ; e>=0 ;e--){
        if(n>=pow(2,e)){
            ans.pb(1) ;
            n-= pow(2,e) ;
        }
        else{
            ans.pb(0) ;
        }
    }
}

void print(vii & pr){
    for(int e= 0;e<pr.size() ; e++){
         cout<<pr[e]<<" " ;
    }
}

int main(){
    int n ;
    cin>>n ;
    vii ans ;
    bintint(n,ans) ;
    print(ans) ;
}