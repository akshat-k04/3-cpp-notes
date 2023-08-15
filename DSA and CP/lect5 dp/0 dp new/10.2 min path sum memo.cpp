// https://www.codingninjas.com/studio/problems/minimum-path-sum_985349

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


int memo(vvii &dp,vvii& cost,int n,int m){
    if(n<0 ||m<0)return 1000000007 ;
    if(dp[n][m]!=-1)return dp[n][m] ;
    return dp[n][m]= cost[n][m] + min(memo(dp,cost,n-1,m),memo(dp,cost,n,m-1)) ;
}

int main(){
    int n,m ;
    cin>>n>>m ;
    vvii cost(n,vii (m,0)) ;
    for(int e=0 ;e<n ;e++){
        for(int f=0;f<m ;f++){
            cin>>cost[e] ;
        }
    }

    vvii dp(n,vii (m,-1)) ;
    dp[0][0]=cost[0][0] ;
    return memo(dp,cost,n-1,m-1) ;
}