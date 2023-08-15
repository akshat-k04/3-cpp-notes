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
typedef vector<vector<int>> vvii;
 
void print(vii& a){int n = a.size() ;for(int e=0 ;e<n ;e++)cout<<a[e] <<' ';cout<<endl ;}

int memo(int n,vii&dp){
    if(dp[n]!=0)return dp[n] ;

    else return dp[n] =memo(n-1,dp)+memo(n-2,dp); ;
}

int main(){
    int t ;
    cin>>t ;
    vii dp(100007) ;
    dp[0]=1;dp[1]=1 ;
    while(t--){
        int n ;
        cin>>n ;
        if(dp[n]==0){
            cout<<memo(n,dp)<<endl ;
        }
        else{
            cout<<dp[n] <<endl ;
        }
    }
}