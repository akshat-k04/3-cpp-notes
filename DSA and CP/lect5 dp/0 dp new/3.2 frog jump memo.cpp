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

ll min (ll a,ll b){
    if(a>b)return b ;
    else return a ;
}

ll memo(vll&dp, int n,vii & heights){
    if(dp[n]!=-1)return dp[n] ;
    return dp[n] = min(memo(dp,n-2)+abs(heights[n]-heights[n-2]),memo(dp,n-1)+abs(heights[n-1]-heights[n])) ;
}

int main(){
    int n;
    cin>>n ;
    vii a(n) ;
    for(int e=0;e<n ;e++)cin>>a[e] ;
    vll dp(n,-1) ;
    dp[0]=0 ;
    if(n>1)dp[1]=abs(a[1]-a[0]) ;
    cout<< memo(dp,n-1,a)<<endl ;
}