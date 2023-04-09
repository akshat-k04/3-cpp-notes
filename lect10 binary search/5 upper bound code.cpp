//solved

// Given an sorted array A of size N. Find number of elements which are less than or equal to B.

// NOTE: Expected Time Complexity O(log N)



// Problem Constraints
// 1 <= N <= 106

// 1 <= A[i], B <= 109



// Input Format
// First agument is an integer array A of size N.

// Second argument is an integer B.



// Output Format
// Return an integer denoting the number of elements which are less than or equal to B.



// Example Input
// Input 1:

//  A = [1, 3, 4, 4, 6]
//  B = 4
// Input 2:

//  A = [1, 2, 5, 5]
//  B = 3


// Example Output
// Output 1:

//  4
// Output 2:

//  2


// Example Explanation
// Explanation 1:

//  Elements (1, 3, 4, 4) are less than or equal to 4.
// Explanation 2:

//  Elements (1, 2) are less than or equal to 3.


 #include <bits/stdc++.h>
using namespace std ;
int main(){
    int n ;
    cin>> n ;
    vector<int> a(n) ;
    for(int e=0 ;e<n ;e++){
        cin>>a[e] ;
    }
    int b ;
    cin>>b ;
    if(a[0]>b){
        cout<<0 <<endl ;
    }
    else{
    int f = n-1 , ini = 0 , mid  ;
    int posi =-1 ;
    
    while(f-ini>1){
        mid=(f+ini)/2 ;
        if(a[mid]>b){
            f = mid ;
        }
        else if(a[mid]<b){
            ini = mid ;
        }
        else{
            posi = mid ;
            break ;
        }
    }
    if(posi==-1){
        if(a[f]<=b){
            posi =f ;
        }
        else {
            posi = ini ;
        }
    }
    
    // we get the index where it is just less than or equal to that number

    int newini = posi ;
    int newposi = posi ;
    while(f-newini>1){
        mid = (newini +f)/2 ;
        if(a[mid]<=b){
            newini=mid ;
        }
        else if(a[mid]>b){
            f= mid ;
        }
    }
    if(a[f]<=b){
        newposi = f ;
    }
    else{
        newposi = newini;
    }
    cout<<newposi+1 <<endl ;
    }
}