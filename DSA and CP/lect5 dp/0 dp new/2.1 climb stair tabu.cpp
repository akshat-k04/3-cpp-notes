// https://www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650

// key concept is we have to jump directly from eighter n-1 or n-2 step

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

void print(vii& a){int n = a.size() ;for(int e=0 ;e<n ;e++)cout<<a[e] <<' ';cout<<endl ;}

void tabu(vll& dp){
    dp[0]=1 ;
    dp[1]=1 ;
    for(int e=2 ;e<dp.size();e++){
        dp[e]=dp[e-1]+dp[e-2] ;
    }
}

int main(){
    int t ;
    cin>>t ;
    vll dp(100006) ;
    tabu(dp) ;
    while(t--){
        int n ;
        cin>>n ;
        cout<<dp[n] <<endl ;
    }
}