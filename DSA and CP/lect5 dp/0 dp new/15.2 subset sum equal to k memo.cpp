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

bool memo(vvii & dp , vii &a , int indx,int target){
    if(target<0)return 0 ;
    if(dp[indx][target]!=-1)return dp[indx][target] ;
    
    if(indx==0){
        if(a[0]== target || target==0)return dp[indx][target]=true ;
    }
    else{
        dp[indx][target]= memo(dp,a,indx-1 , target)|| memo(dp,a,indx-1,target-a[indx]);
        return dp[indx][target] ;
    }
}

int main(){
    int n,k ;
    cin>>n>>k ;
    vii a(n) ;
    for(int e=0 ;e<n ;e++)cin>>a[e] ;
    vvii dp(n, vii(k+1,-1)) ;

    return memo(dp,a,n-1,k) ;

}