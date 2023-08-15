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

int memo(vvii &dp,vii & A, int target, int num){
    if(target<0)return -1 ;
    if(num<0&& target>0)return -1 ;
    if(num<0 && target==0)return 0 ;
    if(dp[num][target]!=100000)return dp[num][target] ;
    int a = memo(dp,A,target,num-1) ;
    int b = memo(dp,A,target-A[num],num-1)  ;
    int ans ;
    if(a==b&& a==-1)ans=-1 ;
    else if(a==-1 || b==-1) ans = max(a,b+1) ;
    else ans= min(a,b+1) ;

    return dp[num][target]= ans ;
}

int main(){
    int n,x ;
    cin>>n>>x ;
    vii a(n) ;
    for(int e=0 ;e<n ;e++)cin>>a[e] ;
    vvii dp(n,vii (x+1,100000)) ;
    cout<<memo(dp,a,x,n-1)<<endl ;
    for(int e= 0;e<n ;e++)print(dp[e]) ;
}