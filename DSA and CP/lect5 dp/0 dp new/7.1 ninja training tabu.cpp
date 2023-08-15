// https://www.codingninjas.com/studio/problems/ninja-s-training_3621003
#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define pob pop_back
#define fir first 
#define sec second
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vii;
typedef vector<vector<int>> vvii;

void print(vii& a){int n = a.size() ;for(int e=0 ;e<n ;e++)cout<<a[e] <<' ';cout<<endl ;}

ll max(ll&a,ll&b){
    if(a>b)return a ;
    else return b ;
}

void tabu(vvll &dp,vvii &score){
    for(int e=1;e<dp.size() ;e++){
        dp[e].pb(max(dp[e-1][1],dp[e-1][2])+score[e][0]) ;
        dp[e].pb(max(dp[e-1][0],dp[e-1][2])+score[e][1]) ;
        dp[e].pb(max(dp[e-1][1],dp[e-1][0])+score[e][2]) ;
    }
}

int main(){
    int n ;
    cin>>n ;
    vvii score(n) ;
    for(int e=0 ;e<n;e++){
        int a,b,c ;cin>>a>>b>>c ;
        score.pb(a) ;score.pb(b) ;score.pb(c) ;
    }
    vvll dp(n) ;
    dp[0]=score[0] ;
    tabu(dp,score) ;
    ll ans = max(dp[n-1][0],dp[n-1][1]) ;
    ans=max(dp[n-1][2],ans) ;
    cout<<ans<<endl ;
}