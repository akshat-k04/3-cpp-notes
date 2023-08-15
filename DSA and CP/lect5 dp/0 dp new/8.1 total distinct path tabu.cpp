// https://www.codingninjas.com/studio/problems/total-unique-paths_1081470

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

void tabu(vvii &dp){
    int n = dp.size() ;
    int m = dp[0].size() ;
    dp[0][0]=1 ;
    for(int e=0 ;e<n ;e++){
        for(int f=0 ;f<m ;f++){
            if(e==0 &&f==0)continue ;
            dp[e][f]=0 ;

            if(e!=0)dp[e][f]= dp[e-1][f] ;

            if(f!=0)dp[e][f]=dp[e][f-1] ;
        }
    }
}

int main(){
    int n,m ;
    cin>>n>>m ;
    vvii dp(n,vii (m,-1)) ;
    tabu(dp) ;
    cout<<dp[n-1][m-1] <<endl ;
}