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

// vector<pair<int,int>> movement = {{1,0},{-1,0},{0,-1},{0,1}} ;
vector<pair<int,int>> movement = {{1,0},{0,-1},{0,1},{-1,0}} ;

bool valid(int r,int c ,int n, int m){
    if(r>=0 && c>=0 && r<n && c<m)return true ;
    return false ;
}


void insider(queue<pair<int,int>> & que, vvii & dp ,vvii & a){
    int r = que.front().fir , c = que.front().sec ;
    que.pop() ;
    for(auto move:movement){
        if(valid(r+move.fir,c+move.sec,a.size(),a[0].size())){
            int temper = dp[r+move.fir][c+move.sec] ;
            dp[r+move.fir][c+move.sec]=max(dp[r+move.fir][c+move.sec],dp[r][c]) ;
            dp[r+move.fir][c+move.sec] = min(a[r+move.fir][c+move.sec],dp[r+move.fir][c+move.sec]) ;
            if(dp[r+move.fir][c+move.sec]!=temper)que.push({r+move.fir,c+move.sec}) ;
        }
    }
}

int solve(vvii& a){
    int n = a.size() , m =a[0].size() ;
    vvii dp(n,vii (m,-1)) ;
    dp[0][0]= a[0][0] ;
    queue<pair<int,int>> que ; que.push({0,0}) ;
    while(que.size()!=0){
        insider(que,dp,a) ;
    }
    for(int e=0;e<n ;e++)print(dp[e]) ;
    return dp[n-1][m-1] ;
}

void maker(vvii & a, vvii & s){ // 0 means stone 1 means path
    vector<pair<int,int>> stones ; int n = a.size() , m = a[0].size() ;
    for(int e=0 ;e<n ;e++)for(int f=0 ;f<m ;f++)if(a[e][f]==0)stones.pb({e,f}) ;
    for(int e=0 ;e<n ;e++)for(int f=0 ;f<m ;f++) for(auto v: stones) s[e][f]=min(s[e][f],abs(e-v.fir)+abs(f-v.sec)) ;
}

int main(){
    int n ,m ;
    cin>>n>>m ;
    vvii a(n,vii(m)) ;
    for(int e=0 ;e<n ;e++)for(int f=0 ;f<m ;f++)cin>>a[e][f] ;
    // cout<<solve(a) ;
    vvii s(n,vii(m,1000000)) ;
    maker(a,s) ;
    for(auto v: s) print(v) ;
    cout<<endl ;
    cout<<solve(s) ;
}