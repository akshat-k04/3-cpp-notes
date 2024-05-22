#include <bits/stdc++.h>
using namespace std ;

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() ,m= text2.size() ;
        vector<vector<int>> dp(n+1,vector<int> (m+1)) ;
        for(int e=1 ;e<=n ;e++){
            for(int f=1 ;f<=m ;f++){
                if(text1[e-1]==text2[f-1])dp[e][f]= dp[e-1][f-1]+1 ;
                else dp[e][f]=max(dp[e-1][f],dp[e][f-1]) ;
            }
        }
        
        return dp[n][m] ;
    }

int main(){
    
}