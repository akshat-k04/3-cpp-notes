// https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954



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

void print(vector<bool>& a){int n = a.size() ;for(int e=0 ;e<n ;e++)cout<<a[e] <<' ';cout<<endl ;}

void tabu(vii &a , int k,vector<vector<bool>> & dp){
    int n = dp.size() ;int m = dp[0].size() ;
    dp[0][0]=true ;
    if(a[0]<m)dp[0][a[0]]=true ;
    for(int e=1 ;e<n ;e++){
        // i have to set dp[1] for this i need dp[0]
        for(int f=0;f<m ;f++){
            if(dp[e-1][f]){
                dp[e][f]=true ;
                if(f+a[e]<m)dp[e][f+a[e]]=true ;
            }
        }
    }
}

int main(){
    int n,k ;
    cin>>n>>k ;
    
    vii a(n) ;
    for(int e=0 ;e<n ;e++)cin>>a[e] ;
    
    vector<vector<bool>> dp(n,vector<bool> (k+1 , false)) ;
    tabu(a,k,dp) ;
    bool ans =false ;
    if(dp[n-1][k])ans=true ;
    cout<<ans<<endl ;
}