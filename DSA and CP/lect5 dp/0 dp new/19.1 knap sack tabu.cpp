// https://www.codingninjas.com/studio/problems/0-1-knapsack_920542

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

void tabu(vvii & dp, vpii & things,int w){
    int maxweight = w ;
    int n = dp.size() ;
    dp[0][0]=0 ;
    if(things[0].fir<=maxweight)dp[0][things[0].fir]= things[0].sec ;
    for(int e=1 ;e<n;e++){
        for(int f=0 ;f<=maxweight;f++){
            if(dp[e-1][f]!=-1){
                dp[e][f]=max(dp[e-1][f],dp[e][f]) ;
                if(f+things[e].fir<=maxweight )dp[e][f+things[e].fir]=max(dp[e-1][f]+things[e].sec ,dp[e][f]);
            }
        }
    }
}

int main(){
    int w,n;cin>>w>>n ;
    vpii things(n) ;
    for(int e=0 ;e<n ;e++)cin>>things[e].fir ;// weight
    for(int e= 0;e<n ;e++)cin>>things[e].sec ;// value
    vvii dp(n,vii(w+1,0)) ;
    tabu(dp,things) ;
    sort(all(dp[n-1])) ;
    return dp[n-1][w] ;
}