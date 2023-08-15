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

int memo(vvii &dp ,int n ,int m){
    if(dp[n][m]!=-1)return dp[n][m] ;
    else if(m==0)dp[n][m]=memo(dp,n-1,m) ;
    else if (n==0)dp[n][m]=memo(dp,n,m-1) ;
    else dp[n][m] = memo(dp,n,m-1) +memo(dp,n-1,m) ;
}

int main(){
    int n,m ;
    cin>>n>>m ;
    vvii dp(n,vii (m,-1)) ;
    dp[0][0]=1 ;
    cout<<memo(dp,n-1,m-1)<<endl ;
}