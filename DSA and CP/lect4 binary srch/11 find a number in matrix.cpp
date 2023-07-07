// done

// Given a matrix of integers A of size N x M and an integer B. Write an efficient algorithm that searches for integer B in matrix A. 

// This matrix A has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than or equal to the last integer of the previous row.
// Return 1 if B is present in A, else return 0.

// NOTE: Rows are numbered from top to bottom, and columns are from left to right.



// Problem Constraints
// 1 <= N, M <= 1000

// 1 <= A[i][j], B <= 106



// Input Format
// The first argument given is the integer matrix A.

// The second argument given is the integer B.



// Output Format
// Return 1 if B is present in A else, return 0.



// Example Input
// Input 1: 

// A = [ 
//       [1,   3,  5,  7]
//       [10, 11, 16, 20]
//       [23, 30, 34, 50]

//     ]
// B = 3
// Input 2:

// A = [

//       [5, 17, 100, 111]
//       [119, 120, 127, 131]

//     ]
// B = 3


// Example Output
// Output 1: 

// 1
// Output 2:

// 0


// Example Explanation
// Explanation 1: 

//  3 is present in the matrix at A[0][1] position so return 1.
// Explanation 2:

//  3 is not present in the matrix so return 0.

#include <bits/stdc++.h>
using namespace std ;
int main(){
    int n , m ;// n is row num , m is column num 
    cin>> n>> m ;
    vector<vector<int>> a ;
    for(int e=0 ;e<n ;e++){
        vector<int> temp(m);
        for(int p=0 ; p<m ;p++){
            cin>>temp[p] ;
        }
        a.push_back(temp) ;
    }
    int b  ;
    cin>>b ;
    //input is done 

    int hi = m*n  ;
    int lo = 0 ;
    int mid ;

    while(hi-lo>1){
        mid = (hi+lo)/2 ;
        int rowind = (mid /m)  ;
        int colind = (mid%m) -1 ;
        if(colind==-1){
            colind = m-1 ;
            rowind-- ;
        }
        if(b>a[rowind][colind]){
            lo = mid ;
        }
        else{
            hi = mid ;
        }
    }

    int rowind = (lo /m)  ;
    int colind = (lo%m) -1 ;
    if(colind==-1){
        colind = m-1 ;
    }
    // cout<<a[rowind][colind]<<endl ;
    if(rowind>=0 && a[rowind][colind]==b){
        cout<< 1<<endl ;
    }
    else {
        rowind= (hi / m)  ;
        colind = (hi%m) -1 ;
        if(colind==-1){
            colind = m-1 ;
            rowind--;
        }
        // cout<<rowind<<endl ;

        if(rowind>=0 &&a[rowind][colind]==b){
            cout<< 1<<endl ;
        }
        else {
            cout<<0<<endl ;
        }
    }
}