// https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261

#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define pob pop_back
//#define fir first 
//#define sec second
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vii;
typedef vector<vector<int>> vvii;

void print(vii& a){int n = a.size() ;for(int e=0 ;e<n ;e++)cout<<a[e] <<' ';cout<<endl ;}

void tabu(vii & dp,vii & a){
    dp[0]=a[0];
    if(dp.size()>1)dp[1]=a[1];
    if(dp.size()>2)dp[2]= a[2]+a[0] ;
    for(int e=3 ;e<dp.size();e++){
        dp[e]= a[e]+max(dp[e-2],dp[e-3]) ;
    }
}

int main(){
    int n ;
    cin>>n ;
    vii a(n) ;
    for(int e=0 ;e<n;e++)cin>>a[e] ;
    vii dp(n) ;
    tabu(dp,a) ;
    if(n==1)cout<<a[0]<<endl ;
    else cout<<max(dp[n-1],dp[n-2]) <<endl ;
}