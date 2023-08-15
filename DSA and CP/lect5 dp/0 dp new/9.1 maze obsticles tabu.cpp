// https://www.codingninjas.com/studio/problems/maze-obstacles_977241

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
typedef vector<vector<long long>> vvll;


void print(vii& a){int n = a.size() ;for(int e=0 ;e<n ;e++)cout<<a[e] <<' ';cout<<endl ;}

void tabu(vvll &dp){ // dp[e][f] tell number of ways to reach there
    int n = dp.size() ;
    int m = dp[0].size() ;
    dp[0][0]+=1 ; //if it is 0 then become 1 ,if -1 then become 0 
    for(int e=0 ;e<n ;e++){
        for(int f=0 ;f<m ;f++){
            if(e==0 &&f==0)continue ;
            if(dp[e][f]==-1){
                dp[e][f]=0 ;
                continue ;
            }
            if(e!=0)dp[e][f]+=dp[e-1][f] ;
            if(f!=0)dp[e][f]+=dp[e][f-1] ;
            dp[e][f]%=1000000007 ;
        }
    }
}

int main(){
    int n,m ;
    vvll dp(n,vii (m,0)) ;
    for(int e=0 ;e<n ;e++){
        for(int f=0 ;f<m ;f++)cin>>dp[e][f] ;
    }
    tabu(dp) ;
    return dp[n-1][m-1] ;
}