#include <bits/stdc++.h>
using namespace std ;

int memo(int n, int m , string & s1, string &s2,vector<vector<int>>& dp){
    if(n<0 || m<0)return 0 ;
    if(dp[n][m]!=-1)return dp[n][m] ;


    if(s1[n]==s2[m])dp[n][m] = 1+ memo(n-1,m-1,s1,s2,dp) ;
    else dp[n][m]=0 ;

    return dp[n][m] ;
}

int lcs(string &s1, string &s2){
    // Write your code here.
    int n = s1.size() , m=s2.size() ;
    vector<vector<int>> dp(n,vector<int> (m,-1)) ;
    int ans=0 ;
    for(int e=0 ;e<n ;e++){
        for(int f=0 ;f<m ;f++){
            ans=max(memo(e,f,s1,s2,dp),ans) ;
        }
    }
    return ans ;
}

int main(){
    
}