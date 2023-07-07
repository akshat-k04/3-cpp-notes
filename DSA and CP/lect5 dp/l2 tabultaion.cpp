//theory 

/*
Tabulation and memoization are two techniques used in dynamic programming to optimize the execution of a function that has repeated and expensive computations. Although both techniques have similar goals, there are some differences between them.

Memoization is a top-down approach where we cache the results of function calls and return the cached result if the function is called again with the same inputs. It is used when we can divide the problem into subproblems and the subproblems have overlapping subproblems. Memoization is typically implemented using recursion and is well-suited for problems that have a relatively small set of inputs.

Tabulation is a bottom-up approach where we store the results of the subproblems in a table and use these results to solve larger subproblems until we solve the entire problem. It is used when we can define the problem as a sequence of subproblems and the subproblems do not overlap. Tabulation is typically implemented using iteration and is well-suited for problems that have a large set of inputs.
*/

//fiboncii in tabulation


//in preev file the time complexity is O(n) ans space complexity is also O(n) 
// here we try to decresae the space complexity to const i.e.O(2) 

 #include <bits/stdc++.h>
 
using namespace std ;

int solve(int t,int & prev1 ,int&prev2){
    int present = 0 ;
    for(int e=2 ;e<= t ;e++){
        present = prev1+prev2 ;
        prev2= prev1 ;
        prev1 = present ;
    }
    return (t>=2)? present:t ;
}


int main(){
    int t;
    cin>>t ;
    int prev1 = 1 , prev2 = 0 ;
    cout<<solve(t,prev1,prev2) ;
}