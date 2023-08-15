// https://www.codingninjas.com/studio/problems/maximum-path-sum-in-the-matrix_797998

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

void tabu(vvii & dp ,vvii & mat){
    int n = dp.size() , m=dp[0].size() ;
    for(int e=0 ;e<m ;e++){
        dp[0][e]=mat[0][e] ;
    }
    for(int e=1 ;e<n ;e++){
        for(int f=0 ;f<m ;f++){
            if(valid(n,m,e-1,f))dp[e][f]=max(dp[e][f],dp[e-1][f]) ;
            if(valid(n,m,e-1,f-1))dp[e][f]=max(dp[e][f],dp[e-1][f-1]) ;
            if(valid(n,m,e-1,f+1))dp[e][f]=max(dp[e][f],dp[e-1][f+1]) ;
            dp[e][f]+=mat[e][f];   
        }
    }
}

int main(){
    int n ,m ;
    cin>>n>>m ;
    vvii mat(n,vii (m)) ;
    for(int e=0 ;e<n ;e++)for(int f=0; f<m ;f++)cin>>mat[e][f] ;
    vvii dp(n,vii (m)) ;
    tabu(dp,mat) ;

    sort(all(dp[n-1])) ;
    cout<<dp[n-1][m-1] <<endl ;
}