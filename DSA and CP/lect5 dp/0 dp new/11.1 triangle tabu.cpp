// https://www.codingninjas.com/studio/problems/triangle_1229398
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

void tabu(vvii& dp,vvii&cost){
    dp[0][0]= cost[0][0] ;
    int n = dp.size() ;
    for(int e=1 ;e<n ;e++){
        for(int f=0 ;f<dp[e].size();f++){
            if(f==0)dp[e][f]=dp[e-1][f]+cost[e][f] ;
            else if(f==e)dp[e][f]=dp[e-1][f-1]+cost[e][f] ;
            else dp[e][f]=cost[e][f]+min(dp[e-1][f-1],dp[e-1][f]) ;
        }
    }
}

int main(){
    int n; 
    cin>>n ;
    vvii cost(n) ;
    vvii dp(n) ;
    for(int e=0 ;e<n ;e++){
        for(int f=0 ;f<=e ;f++){
            int h ;
            cin>>h ;
            cost[e].pb(h) ;
            dp[e].pb(-1) ;
        }
    }

    tabu(dp,cost) ;
    sort(dp[n-1].begin(),dp[n-1].end()) ;
    return dp[n-1][0] ;
}