// this solution has tc:- coins.size()*target  sc:- same as tc 
// try to do it in sc:- target 

// https://www.codingninjas.com/studio/problems/minimum-elements_3843091
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

int tabu(vii & coin , int target){
    vvii dp(coin.size() , vii (target+2,100000)) ; // tells about mini coins

    int temper =0 ; int counter= 0 ;
    while(temper<=target){
        dp[0][temper]=counter ;
        temper+= coin[0] ; counter++ ;
    }
    for(int e=1 ;e<coin.size() ;e++){
        for(int f=0 ;f<=target ;f++){
            dp[e][f]=min(dp[e-1][f],dp[e][f]) ;
            if(f+coin[e]<=target) dp[e][f+coin[e]]=min(1+dp[e][f],dp[e][f+coin[e]]) ;
        }
        
    }
    
    if(dp[coin.size()-1][target]==100000) return -1 ;
    return dp[coin.size()-1][target] ;
}

int main(){
    int n ;cin>>n ;
    vii coin(n) ;
    for(int e=0 ;e<n ;e++)cin>>coin[e] ;
    int target ;cin>>target ;
    cout<<solve(coin,target) ;
}