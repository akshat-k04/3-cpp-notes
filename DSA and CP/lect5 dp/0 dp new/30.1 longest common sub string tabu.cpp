#include <bits/stdc++.h>
using namespace std ;

int lcs(string &s1, string &s2){
    // Write your code here.
    int n = s1.size() , m = s2.size() ;

    vector<vector<int>> dp(n+1 ,vector<int> (m+1)) ;

    int ans=0 ;
    for(int e=1 ;e<=n ;e++){
        for(int f=1 ;f<=m ;f++){
            if(s1[e-1]==s2[f-1])dp[e][f]=1+dp[e-1][f-1] ;
            else dp[e][f]=0 ;
            ans=max(dp[e][f],ans) ;
        }
    }

    return ans ;
}

int main(){
    
}