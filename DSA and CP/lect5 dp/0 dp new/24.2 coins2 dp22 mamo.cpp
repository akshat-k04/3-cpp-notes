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

int memo(vii & a , int target , int indx,vvii & dp){
    if(indx>=a.size()|| target<0)return 0 ;
    if(dp[indx][target]!=-1)return dp[indx][target] ;
    return dp[indx][target]= memo(a,target,indx+1) +memo(a,target-a[indx],indx) ;
}

int main(){
    int n ;cin>>n ;
    vii a(n) ;
    for(int e=0 ;e<n ;e++)cin>>a[e] ;
    int target ;cin>>target ;
    vvii dp(n,vii (target+1,-1)) ;
    for(int e=0 ;e<n;e++){
        if(a[e]<=target)dp[e][a[e]]++;
    }
    cout<<memo(a,target,indx,dp) ;
}