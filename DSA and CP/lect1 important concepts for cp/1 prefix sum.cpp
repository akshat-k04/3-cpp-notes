/*
1. it is used generally in query based question where we are given with no. of query and for each query we have to find the ans in O(1) time complexity of may be o(logn) time compleaxity

2. eg q link :-https://leetcode.com/problems/minimum-size-subarray-sum/

3. q is :-Given an array of positive integers nums and a positive integer target, return the minimal length of a 
          subarray
          whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
*/

#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define pob pop_back
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef vector<long long> vll;
typedef vector<int> vii;


//solution here 

int solve(vii &a ,int target){
    int n =a.size() ;
    vll sum(n) ;
    sum[0]=a[0] ;
    for(int e=1 ;e<n ;e++){
        sum[e] = sum[e-1]+a[e] ;
    }
    int ans = 10000000 ;
    for(int e=0 ;e<n ;e++){
        int num = sum[e] - target ;
        if(num>=0){
            int  index = upper_bound(sum.begin(),sum.end(),num) -sum.begin() ;
            index-- ;
            ans= min(ans,e-index) ;
        }
    }
    if(ans==10000000){
        return 0 ;
    }
    else{
        return ans ;
    }
}

int main(){
    int n ;
    cin>>n ;
    vii a;
    for(int e=0 ;e<n ;e++){
        int h; 
        cin>>h ;
        a.pb(h) ;
    }
    int target ;
    cin>>target ;
    cout<<solve(a,target) ;
}