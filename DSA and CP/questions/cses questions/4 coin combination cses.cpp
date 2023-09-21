// https://cses.fi/problemset/task/1635

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

int main(){
    int n ,x ;
    cin>>n>>x ;
    vii a(n) ;
    for(int e=0 ;e<n ;e++)cin>>a[e] ;

    vii dp(x+1) ;dp[0]=1 ;
    for(int target = 1 ;target<=x ;target++){
        for(int f=0 ;f<a.size() ;f++){
            if(target-a[f]<0)continue ;
            else dp[target]+= dp[target-a[f]] ;
            dp[target]%=1000000007 ;
        }
    }
    cout<<dp[x]<<endl ;
}