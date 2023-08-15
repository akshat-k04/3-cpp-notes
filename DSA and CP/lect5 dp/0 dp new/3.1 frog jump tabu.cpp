// https://www.codingninjas.com/studio/problems/frog-jump_3621012


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

void tabu(vll &dp,vii &heights){
    if(heights.size()==1)return ;
    dp[0]=0 ;
    dp[1]= abs(heights[1]-heights[0]) ;
    for(int e=2 ;e<dp.size();e++){
        dp[e]= dp[e-1]+abs(heights[e]-heights[e-1]) ;
        if(dp[e]> dp[e-2]+abs(heights[e]-heights[e-2])){
            dp[e]=dp[e-2]+abs(heights[e]-heights[e-2]) ;
        }
    }
}

int main(){
    int n; 
    cin>>n ;
    vii a(n) ;
    for(int e=0 ;e<n ;e++)cin>>a[e] ;
    vll dp(n) ;
    tabu(dp,a) ;
    cout<<tabu[n-1] ;
}