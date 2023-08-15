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

bool valid(int n,int m, int x,int y){
    if(x>=0 && x<n && y>=0 && y<m )return true ;
    return false ;
}

int memo(vvii & a , vvii& dp ,int row,int col){
    int n = dp.size() , m=dp[0].size() ;
    if(row==0){
            return dp[0][col]=a[0][col] ;
    }
    else if(dp[row][col]!=-1000000007){
        return dp[row][col] ;
    }
    else{
        if(valid(n,m,row-1,col))dp[row][col]=max(dp[row][col],memo(a,dp,row-1,col)) ;
        if(valid(n,m,row-1,col-1))dp[row][col]=max(dp[row][col],memo(a,dp,row-1,col-1)) ;
        if(valid(n,m,row-1,col+1))dp[row][col]=max(dp[row][col],memo(a,dp,row-1,col+1)) ;
        dp[row][col]+=a[row][col];
        return dp[row][col] ;
    }
}

int main(){
    int n,m ;cin>>n>>m ;
    vvii a(n, vii (m)) ;
    for(int e=0 ;e<n ;e++){
        for(int f=0 ;f<m ;f++){
            cin>>a[e][f] ;
        }
    }
    vvii dp(n,vii (m,-1000000007)) ;
    int ans=-1000000007 ;
    for(int e=0; e<m ;e++){
        ans = max(ans , memo(a,dp,n-1,e)) ;
    }
    cout<<ans<<endl ;
}