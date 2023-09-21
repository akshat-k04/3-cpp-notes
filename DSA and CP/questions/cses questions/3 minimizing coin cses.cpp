// https://cses.fi/problemset/task/1634

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

int memo(vii & ans , int x , vii & a){
    if(x==0)return 0 ;
    if(ans[x]!=10000000)return ans[x] ;
    for(auto child: a){
        if(x-child<0)continue ;
        ans[x]= min(memo(ans ,x-child, a)+1,ans[x]) ;
    }
    if(ans[x]==10000000)ans[x]=20000000 ;
    // cout<<ans[x]<<" ";
    return ans[x] ;
}


int main(){
    int n,x ;cin>>n>>x ;
    vii a(n) ;
    for(int e=0 ;e<n ;e++)cin>>a[e] ;

    vii ans (x+1,10000000) ;
    memo(ans,x,a) ;
    if(ans[x]>=10000000)cout<<-1<<endl ;
    else cout<<ans[x]<<endl ;
}