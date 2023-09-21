https://www.codingninjas.com/studio/problems/target-sum_4127362

/*
here we have to add + , - sign before each element now then tell the target sum achive or not 
in directly we have to find the 2 sub sequence whose diff is target
in directly we have to find the sub sequence whose sum is (array_sum-target)/2 ;
*/

#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define pob pop_back
#define fir first 
#define sec second
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vii;
typedef vector<vector<int>> vvii;

void print(vii& a){int n = a.size() ;for(int e=0 ;e<n ;e++)cout<<a[e] <<' ';cout<<endl ;}

int tabu(vii & a , int target){
    int sum =0 ;
    for(int e=0 ;e<a.size();e++)sum+=a[e] ;
    int reqsum = (sum+target) ;
    if(reqsum%2==1)return 0 ;
    
    reqsum/=2 ;

    vvii dp(a.size() , vii (reqsum+1,0)) ;
    if(a[0]<=reqsum)dp[0][a[0]]++ ;
    dp[0][0]++ ;
    for(int e=1 ;e<a.size() ;e++){
        for(int f=0 ;f<=reqsum;f++){
            dp[e][f]=dp[e-1][f] ;
            if(f-a[e]>=0) dp[e][f]+=dp[e-1][f-a[e]] ;
        }
    }
    
    return dp[a.size()-1][reqsum] ;
}

int main(){
    int t ;cin>>t ;
    while(t--){
        int n ;cin>>n ;
    int target ;cin>>target ;

    vii a(n) ;
    for(int e=0 ;e<n ;e++)cin>>a[e] ;
    cout<<tabu(a,target) <<endl;
    }
}