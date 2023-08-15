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

int memo(int n,vii & dp,vii &a){
    if(dp[n]!=-1)return dp[n] ;
    else return dp[n]=a[n]+max(memo(n-2,dp,a),memo(n-3,dp,a)) ;
}

int main(){
    int t ;
    cin>>t;
    while(t--){
    int n;
    cin>>n; 
    vii a(n) ;
    for(int e=0 ;e<n ;e++)cin>>a[e] ;
    vii dp(n,-1) ;
    if(n==1)cout<<a[0]<<endl;
    else {
        dp[0]=a[0] ;
        dp[1]= a[1] ;
        if(n>2) dp[2]=a[2]+a[0] ;
        cout<< max(memo(n-1,dp,a),memo(n-2,dp,a))<<endl ;
    }
    }
}