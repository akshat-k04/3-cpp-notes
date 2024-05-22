// https://www.codingninjas.com/studio/problems/unbounded-knapsack_1215029

#include <bits/stdc++.h>
using namespace std ;


int unboundedKnapsack(int n, int max_weight, vector<int> &value, vector<int> &weight){
    
    vector<vector<int>> dp(n, vector<int> (max_weight+1)) ;

    for(int e=0 ;e*weight[0]<= max_weight ;e++)dp[0][e*weight[0]]= e*value[0] ;

    for(int e=1 ;e<n ;e++){
        for(int f=0 ;f<=max_weight ;f++){
            dp[e][f] = max(dp[e-1][f],dp[e][f]) ;
            if(f+weight[e]<=max_weight)dp[e][f+weight[e]]=max(dp[e][f]+value[e],dp[e][f+weight[e]]) ;
        }
    }
    int ans=0 ;
    for(int e=0 ;e<=max_weight ;e++)ans=max(ans, dp[n-1][e]) ;
    return ans ;
}

int main(){
    
}