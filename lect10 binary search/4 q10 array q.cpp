// not done 

// Given an array A containing N integers.

// You need to find the maximum sum of triplet ( Ai + Aj + Ak ) such that 0 <= i < j < k < N and Ai < Aj < Ak.

// If no such triplet exist return 0.



// Problem Constraints
// 3 <= N <= 105.

// 1 <= A[i] <= 108.



// Input Format
// First argument is an integer array A.



// Output Format
// Return a single integer denoting the maximum sum of triplet as described in the question.



// Example Input
// Input 1:

//  A = [2, 5, 3, 1, 4, 9]
// Input 2:

//  A = [1, 2, 3]


// Example Output
// Output 1:

//  16
// Output 2:

//  6


// Example Explanation
// Explanation 1:

//  All possible triplets are:-
//     2 3 4 => sum = 9
//     2 5 9 => sum = 16
//     2 3 9 => sum = 14
//     3 4 9 => sum = 16
//     1 4 9 => sum = 14
//   Maximum sum = 16
// Explanation 2:

//  All possible triplets are:-
//     1 2 3 => sum = 6
//  Maximum sum = 6

 #include <bits/stdc++.h>
using namespace std ;
int main(){
    int n ;
    cin>> n ;
    vector<int> fk(n) ;
    for(int e=0 ;e<n ;e++){
        cin>> fk[e] ;
    }
    //input is done 
    vector<pair<int,int>> a ;
    for(int e=0;e<n;e++){
        
        a.push_back({fk[e],e}) ;
    }
    
    sort(a.begin() ,a.end()) ;
    int ans =0 ;
    for(int e=n-1 ; e>=0 ;e--){
        int num;
        int sum  ;
        // cout<<a[e].first <<" " ;
        for(int gh =e-1 ;gh>=0 ;gh--){
            if(a[gh].second<a[e].second){
                num=2 ;
                sum = a[gh].first+a[e].first ;
                for(int p=gh-1 ; p>=0 ;p--){
                    if(a[p].second<a[gh].second){
                        num=3 ;
                        sum += a[p].first ;
                        
                        break ;
                    }
                
                }
            }
            if(num==3){ans = max(ans , sum) ;}
            num = 2 ;
        }
        // cout<<endl ;
        
    }
    cout<<ans<<endl ;
    

}