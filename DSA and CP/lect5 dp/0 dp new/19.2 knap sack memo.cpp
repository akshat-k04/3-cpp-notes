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

int memo(vvii & dp, vpii &things, int weightleft,int num){
    if(num<0)return 0 ;
    if(dp[num][weightleft]!=-1)return dp[num][weightleft] ;
    int a = memo(dp,things,weightleft,num-1) ;
    int b= 0;
    if(weightleft-things[num].fir>=0)b = memo(dp,things,weightleft-things[num].fir,num-1)+things[num].sec ;
    return dp[num][weightleft]=max(a,b) ;
}
int main(){
    int maxweight ,n ;
    cin>>maxweight>>n ;
    vpii things(n) ;
    for(int e=0 ;e<n ;e++)cin>>things[e].fir ;
    for(int e=0 ;e<n ;e++)cin>>things[e].sec; 
    vvii dp(n,vii (maxweight+1,-1)) ;
    int ans= 0;
    return memo(dp,things,maxweight,n-1) ;
}