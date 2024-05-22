#include <bits/stdc++.h>
using namespace std ;

int memo(int n , int max_weight, vector<int> & weight , vector<int> &profit , vector<vector<int>> & dp){
    
    if(n<0)return 0 ;
    if(max_weight<0)return -profit[n] ;
    if(dp[n][max_weight]!=-1)return dp[n][max_weight] ;

    dp[n][max_weight]=max(profit[n]+memo(n,max_weight-weight[n],weight,profit,dp),memo(n-1 ,max_weight,weight,profit,dp)) ;
    return dp[n][max_weight] ;
}


int unboundedKnapsack(int n, int max_weight, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int> (max_weight+1,-1)) ;
    return memo(n-1,max_weight,weight,profit,dp) ;
}

int main(){
    
}