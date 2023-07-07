// Given an array of ‘N’  positive integers, we need to return the maximum sum of 
// the subsequence such that no two elements of the subsequence are adjacent elements 
// in the array.

// Note: A subsequence of an array is a list with elements of the array where some 
// elements are deleted ( or not deleted at all) and the elements should be in the same
// order in the subsequence as in the array.



 #include <bits/stdc++.h>
using namespace std ;


//DP (memoization) :- not correct 
int solve(vector<int> &a ,vector<int> & ans,int indx){
    int n = a.size() ;
    if(indx>=n-2){
        // cout<<indx<<" ";
        ans[indx]= a[indx ] ;
        if(indx == n-2){
            return max(ans[indx],ans[indx+1]) ;
        }
        else{
            return ans[indx] ;
        }
    }
    else {
        for(int e=indx+2 ;e<n ;e++){
            if(ans[e]==-1){
                ans[e]= solve(a,ans ,e);    
            }
            
        }
        int maxer =-1 ;
        for(int e=indx+2 ; e<n ;e++){
            if(maxer ==-1){
                maxer = ans[e] ;
            }
            else{
                maxer = max(maxer , ans[e]) ;
            }
        }
        return (a[indx] + maxer) ;
    }
}

int main(){
    int t ;
    cin>> t ;
    for(int r=0 ;r<t ;r++){
        int n ;
        cin>>n ;
        vector<int> a(n),ans(n,-1) ;
        for(int e=0 ;e<n ;e++){
            cin>> a[e] ;
        }
        // input is done 
        
        ans[n-1]= a[n-1] ;
        ans[0] =solve(a , ans,0) ;
        int mxi =-1 ;
        for(int e=0 ;e<n ;e++){
            cout<<ans[e] <<" ";
            if(mxi==-1){
                mxi = ans[e] ;
            }
            mxi = max(mxi , ans[e]) ;
        }
        cout<<mxi <<endl ;
    }
}










//DP :- (tebulation) base to top
// int solve(vector<int> &a , vector<int> &ans,int maxer){
//     int n = a.size() ;
//     ans[n-1]= a[n-1] ;
//     ans[n-2]= a[n-2] ;
//     for(int e=n-3 ; e>=0 ;e--){
//         maxer = max(maxer , ans[e+2]) ;
//         ans[e]= a[e]+maxer ;
//     }
//     int maxi =-1 ;
//     for(int e=0 ;e<n ;e++){
//         if(maxi==-1){
//             maxi= ans[e] ;
//         }
//         else {
//             maxi = max(maxi, ans[e]) ;
//         }
//     }
//     return maxi ;
// }

// int main(){
//     int t ;
//     cin>> t ;
//     for(int r=0 ;r<t ;r++){
//         int n ;
//         cin>>n ;
//         vector<int> a(n),ans(n,-1) ;
//         for(int e=0 ;e<n ;e++){
//             cin>> a[e] ;
//         }
//         // input is done 
//         int maxer=a[n-1] ;
        
//         cout<<solve(a , ans,maxer)<<endl ;
//     }
// }