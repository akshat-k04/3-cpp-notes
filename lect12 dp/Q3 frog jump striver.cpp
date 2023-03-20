// Given a number of stairs and a frog, the frog wants to climb 
// from the 0th stair to the (N-1)th stair. At a time the frog 
// can climb either one or two steps. A height[N] array is also 
// given. Whenever the frog jumps from a stair i to stair j, the 
// energy consumed in the jump is abs(height[i]- height[j]), where
//  abs() means the absolute difference. We need to return the 
// minimum energy that can be used by the frog to jump from stair 
// 0 to stair N-1.


 #include <bits/stdc++.h>
using namespace std ;

//DP(memoization) :- top to base 

int solve(vector<int> &a , vector<int> &ans,int indx){
    if(indx==0 || indx== 1){
        if(indx==0){
            ans[indx]=0 ;
            return 0 ;
        }
        else {
            int k= abs(a[0]-a[1]) ;
            ans[indx]= k ;
            return k ;
        }
    }
    else {
        if(ans[indx]==-1){
            
            int k = min(abs(a[indx]-a[indx-1])+solve(a, ans ,indx-1),abs(a[indx]-a[indx-2])+solve(a, ans,indx-2)) ;
            ans[indx]= k ;
            return k ;
        }
        else {
            return ans[indx] ;
        }
    }
}
int main(){
    int t ;
    cin>>t ;
    for(int r=0 ;r<t ;r++){
        int n ;
        cin>>n ;
        vector<int> a(n),ans(n,-1) ;
        for(int e=0 ;e<n ;e++){
            cin>>a[e] ;
        }
        // input is done
        cout<<solve(a,ans,n-1)<<endl  ;
    }
}








//DP :- (tebulation) base to top
// void solve(vector<int> &height , vector<int>&ans){


    
//     int n = height.size() ;
//     for(int e= n-2; e>=0 ; e--){
//         if(e==n-2||e==n-3){
//             ans[e]= abs(height[e]-height[n-1]) ;
//         }
//         else {
//             int temp1 =abs(height[e]-height[e+1]) ;
//             int temp2 = abs(height[e]-height[e+2]) ;
//             temp1+= ans[e+1] ;
//             temp2+= ans[e+2] ;
//             ans[e] = min(temp1,temp2) ;
//         }
//     }
//     cout<<ans[0]<<endl ;
// }


// int main(){
//     int t ;
//     cin>>t ;
//     for(int r=0 ;r<t ;r++){

//     int n ;
//     cin>>n ;
//     vector<int> height(n),ans(n,-1) ;
//     for(int e=0 ; e<n ;e++){
//         cin>>height[e] ;
//     }
    
    
    
//     solve(height ,ans) ;
//     }

// }




//recursion
// void solve(vector<int> &height , int &ans,int indx,int sum ){
//     if(indx== height.size()-1){
//         ans=(ans==-1)?sum: min(sum ,ans) ;
//         // cout<<"KK";
//     }
//     else if(indx<height.size()-1){
//         // cout<<indx<<" " ;
//         int k = sum +abs(height[indx]-height[indx+1]) ;
//         // cout<<k<<" ";
//         solve(height , ans , indx+1 , k) ;
//         k=sum +abs(height[indx]-height[indx+2]) ;
//         solve(height , ans , indx+2 , k) ;
//     }
// }




// int main(){
//     int t ;
//     cin>>t ;
//     for(int r=0 ;r<t ;r++){

//     int n ;
//     cin>>n ;
//     vector<int> height(n) ;
//     for(int e=0 ; e<n ;e++){
//         cin>>height[e] ;
//     }
//     int ans = -1 ;
//     solve(height ,ans,0,0) ;
//     cout<< ans<<endl ;
//     }

// }