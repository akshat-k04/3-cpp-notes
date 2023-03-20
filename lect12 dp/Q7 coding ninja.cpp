// A Ninja has an ‘N’ Day training schedule. He has to perform one of these three activities (Running, Fighting Practice, or Learning New Moves) each day. There are merit points associated with performing an activity each day. The same activity can’t be performed on two consecutive days. We need to find the maximum merit points the ninja can attain in N Days.

// We are given a 2D Array POINTS of size ‘N*3’ which tells us the merit point of specific activity on that particular day. Our task is to calculate the maximum number of merit points that the ninja can earn.
// problem linnk:-https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define pob pop_back
//#define fir first 
//#define sec second
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vii;

const ll largestLL= 1e18;
const int largestI = 1e9;
const ll primeInt2 = 1000000007;
const int primeInt = 998244353;

//solution here 


// tabulation DP
void solve(vector<vector<int>> &a , vector<vector<int>> &dp){
    int n ;
    n = a.size() ;
    for(int e=n-1 ; e>=0 ;e--){
       
        if(e==n-1){
            dp[e].pb(a[e][0]);
            dp[e].pb(a[e][1]);
            dp[e].pb(a[e][2]);
        }
        else{
            int mx ;
            mx = a[e][0] ;
            mx +=  max(dp[e+1][1],dp[e+1][2]) ;
            dp[e].pb(mx) ;

            mx = a[e][1] ;
            mx +=  max(dp[e+1][0],dp[e+1][2]) ;
            dp[e].pb(mx) ;

            mx = a[e][2] ;
            mx +=  max(dp[e+1][1],dp[e+1][0]) ;
            dp[e].pb(mx) ;

        }
    }
}

int main(){
    int n ;
    cin>> n ;
    vector<vector<int>> a(n);
    for(int e=0 ;e<n ;e++){
        int p,q,r ;
        cin>>p>>q>>r ;
        a[e].pb(p);
        a[e].pb(q);
        a[e].pb(r);
    }
    //input is done 
    vector<vector<int>> dp(n) ;
    solve(a, dp) ;
    cout<<max(max(dp[0][0],dp[0][1]),dp[0][2])<<endl ;
}


















//recursive solution
// void solve(vector<vector<int>> & a,vii &dp,int use,int sum,int indx){
//     int n = a.size() ;
//     if(indx==n){
//         dp.pb(sum) ;

//     }
//     else{
//         if(use==-1){
//             sum+= a[indx][0];
//             solve(a,dp ,0,sum,indx+1) ;
//             sum-= a[indx][0] ;
    
//             sum+= a[indx][1];
//             solve(a,dp ,1,sum,indx+1) ;
//             sum-= a[indx][1] ;

//             sum+= a[indx][2];
//             solve(a,dp ,2,sum,indx+1) ;
//             sum-= a[indx][2] ;
//         }
//         else{
//             if(use==0){
//                 sum+= a[indx][1];
//                 solve(a,dp ,1,sum,indx+1) ;
//                 sum-= a[indx][1] ;

//                 sum+= a[indx][2];
//                 solve(a,dp ,2,sum,indx+1) ;
//                 sum-= a[indx][2] ;
//             }
//             else if(use==1){
//                 sum+= a[indx][0];
//                 solve(a,dp ,0,sum,indx+1) ;
//                 sum-= a[indx][0] ;

//                 sum+= a[indx][2];
//                 solve(a,dp ,2,sum,indx+1) ;
//                 sum-= a[indx][2] ;
//             }
//             else{
//                 sum+= a[indx][1];
//                 solve(a,dp ,1,sum,indx+1) ;
//                 sum-= a[indx][1] ;

//                 sum+= a[indx][0];
//                 solve(a,dp ,0,sum,indx+1) ;
//                 sum-= a[indx][0] ;
//             }
//         }
//     }
        
// }

// int main(){
//     int n ;
//     cin>>n ;
//     vector<vector<int>> a(n) ;
//     for(int e=0 ;e<n ;e++){
//         int p,q,r ;
//         cin>>p>>q>>r ;
//         a[e].pb(p);
//         a[e].pb(q);
//         a[e].pb(r);
//     }
//     //input is done 
//     vii dp ;
//     solve(a,dp,-1,0,0) ; // values , store ans , use , sum ,indx
//     sort(all(dp)) ;
//     cout<<dp[dp.size()-1]<<endl ;
// }