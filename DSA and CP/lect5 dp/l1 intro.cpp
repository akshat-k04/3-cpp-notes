
// Dynamic Programming can be described as storing answers to various sub-problems to be used later whenever required to solve the main problem.

// The two common dynamic programming approaches are:

// Memoization: Known as the “top-down” dynamic programming, usually the problem is solved in the direction of the main problem to the base cases.
// Tabulation: Known as the “bottom-up ” dynamic programming, usually the problem is solved in the direction of solving the base cases to the main problem


//we can do space optimisation in tabulation 


//we can write DP algo in 2 way base to top (tabulation) and top to base (mamoization) ;








// fibonacci using dp 
 #include <bits/stdc++.h>
 #define ll long long 
using namespace std ;
vector<ll int>dp(100001 ,-1);

ll int solve(int t){
    //DP (mamoizetion) :-
    // if(dp[t]==-1){
    //     ll int v = (solve(t-1)+solve(t-2)) ;
    //     dp[t]= v ;
    //     return v ;
    // }
    // else {
    //     return dp[t] ;
    // }


    //DP(tabulation):-
    for(int e=2 ;e<=t ;e++){
        dp[e]=dp[e-1]+dp[e-2] ;
    }
    return dp[t] ;

    //recursion :-
    // if(t<=1){
    //     return t ;
    // }
    // else{
    //     return (solve(t-1)+solve(t-2)) ;
    // }
}

int main(){
    int t; 
    cin>>t;
    dp[0]=0 ;
    dp[1] =1 ;
    cout<<solve(t) ;
}