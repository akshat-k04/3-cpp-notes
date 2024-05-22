#include <bits/stdc++.h>
using namespace std ;
    int memo(string &s1, string &s2 , int n,int m,vector<vector<int>> & dp){
        if(n<0||m<0)return 0 ;
        if(dp[n][m]!=-1)return dp[n][m] ;
        if(s1[n]==s2[m])dp[n][m]= 1+ memo(s1,s2,n-1,m-1,dp) ;
        else dp[n][m]=max(memo(s1,s2,n,m-1,dp),memo(s1,s2,n-1,m,dp)) ;

        return dp[n][m] ;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int> (text2.size(),-1)) ;
        return memo(text1,text2,text1.size()-1 , text2.size()-1,dp) ;
    }
int main(){
    
}