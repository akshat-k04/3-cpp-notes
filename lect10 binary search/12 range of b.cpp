// done


// Given a sorted array of integers A(0 based index) of size N, find the starting and the ending position of a given integer B in array A.

// Your algorithm's runtime complexity must be in the order of O(log n).

// Return an array of size 2, such that the first element = starting position of B in A and the second element = ending position of B in A, if B is not found in A return [-1, -1].



// Problem Constraints
// 1 <= N <= 106

// 1 <= A[i], B <= 109



// Input Format
// The first argument given is the integer array A.

// The second argument given is the integer B.



// Output Format
// Return an array of size 2, such that the first element = starting position of B in A and the second element = the ending position of B in A if B is not found in A return [-1, -1].



// Example Input
// Input 1:

//  A = [5, 7, 7, 8, 8, 10]
//  B = 8
// Input 2:

//  A = [5, 17, 100, 111]
//  B = 3


// Example Output
// Output 1:

//  [3, 4]
// Output 2:

//  [-1, -1]


// Example Explanation
// Explanation 1:

//  The first occurence of 8 in A is at index 3.
//  The second occurence of 8 in A is at index 4.
//  ans = [3, 4]
// Explanation 2:

//  There is no occurence of 3 in the array.

 #include <bits/stdc++.h>
using namespace std ;
int main(){
    int n ;
    cin>> n ;
    vector<int> a(n) ;
    for(int e =0 ;e<n ;e++){
        cin>>a[e] ;
    }
    int b ;
    cin>>b ;
    // input is done 
    int lo =0 , hi=n-1 , mid ;
    int position = -1; 
    vector<int> ans(2) ;
    while(hi-lo>1){
        mid =(hi+lo)/2 ;
        if(a[mid]>b){
            hi = mid ;
        }
        else {
            lo = mid ;
        }
    }
    if(a[hi]==b){
        position = hi ;
    }
    else{
        if(a[lo]==b){
            position = lo ;
        }
        else {
            // cout<<-1 <<endl ;
            ans[0] =-1 ;
            ans[1]= -1 ;
            return ans ;
            exit(0) ;
        }
    }
    // now we have position 
    // make 2 part 

    lo = 0 ; hi = position ; 
    while(hi-lo>1){
        mid = (hi+lo)/2 ;
        if(a[mid]== b){
            hi = mid ;
        }
        else {
            lo = mid ;
        }
    }
    if(a[lo]==b){
        ans[0] = lo ;
    }
    else {
        ans[0] = hi ;
    }


    // this is for next half 
    lo = position ; hi = n-1 ; 
    while(hi-lo>1){
        mid = (hi+lo)/2 ;
        if(a[mid]== b){
            lo = mid ;
        }
        else {
            hi = mid ;
        }
    }
    if(a[hi]==b){
        ans[1] = hi ;
    }
    else {
        ans[1] = lo ;
    }
    // cout<<ans[0]<<" "<<ans[1]<<endl ;
    return ans ;
}