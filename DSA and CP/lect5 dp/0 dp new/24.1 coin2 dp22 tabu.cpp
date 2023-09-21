// https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_630471

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
typedef vector<vector<ll>> vvll;

void print(vii& a){int n = a.size() ;for(int e=0 ;e<n ;e++)cout<<a[e] <<' ';cout<<endl ;}

void tabu(vii & a , int target, vvll & dp){
    int temp=0 ;
    while(temp<=target){
        dp[0][temp]++ ;
        temp+=a[0] ;
    }
    for(int e=1;e<n ;e++){
        for(int f=0 ;f<=target;f++){
            dp[e][f]+=dp[e-1][f] ;
            if(f+a[e]<=target)dp[e][f+a[e]]+=dp[e][f] ;
        }
    }
}

int main(){
    int n ;cin>>n ;
    vii a(n) ;for(int e=0 ;e<n ;e++)cin>>a[e] ;

    int target ;cin>>target ;
    vvll dp(n, vii (target+1 ,-1)) ;
    tabu(a, target, dp) ;
    cout<< a[n-1][target] ;
}