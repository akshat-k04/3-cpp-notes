//solved

// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step
 

// Constraints:

// 1 <= n <= 45

 #include <bits/stdc++.h>
 #define ll long long 
using namespace std ;

ll int solve(int n,ll int prev1 ,ll int prev2){

    //dp(tabulation) :- 
    ll int present  = 0 ;
    for(int e=3 ;e<=n ;e++){
        present = prev1+prev2 ;
        prev2 = prev1 ;
        prev1= present ;
    }

    return present ;

    //recursive approch
    // if(n<=2){
    //     return n ;
    // }
    // else{
    //     return (solve(n-1)+solve(n-2)) ;
    // }
}

int main(){
    int n ;
    cin>>n ;
    if(n<=2){
        cout<<1<<endl ;
    }
    else{
        cout<<solve(n,2,1) ;
    }
    
}