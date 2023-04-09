// solved

// Problem Statement: There is a new barn with N stalls and C cows. The stalls are located on a straight line at positions x1,….,xN (0 <= xi <= 1,000,000,000). We want to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

// Examples:

// Input: No of stalls = 5 
//        Array: {1,2,8,4,9}
//        And number of cows: 3

// Output: One integer, the largest minimum distance 3


 #include <bits/stdc++.h>
using namespace std ;
int n ;
int cows ;
vector<int> stalls ;
bool satisfy(int minDist){
    int cw = cows ;
    int last = -1 ;
    for(int e=0 ;e<n ;e++){
        if(stalls[e]-last >=minDist || last ==-1){
            last = stalls[e] ;
            cw-- ;
        }
        if(cw==0){
            return true ;
        }
    }
    return false ;
}
int main(){
    
    cin>> n ;
    
    for(int e=0 ;e<n ;e++){
        int h ;
        cin>> h ;
        stalls.push_back(h) ;
    }
    sort(stalls.begin() , stalls.end()) ;
    cin>> cows ;
    // input is done 

    for(int e=0 ;e<n ;e++){
        if(!satisfy(e)){
            cout<<e-1 <<endl ;
        }
    }
}