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

vii movements = {-1,0,1} ;

bool valid(int cols ,int a,int b){
    if(a>=0 && b>=0 && cols>a && cols>b)return true ;
    else return false ;
}

int memo(vector<vvii> & dp, vvii &chocolate, int row,int cola,int colb){
    int n=chocolate.size() ; int m = chocolate[0].size() ;
    if(row==0){
        int tempa=chocolate[row][cola] ;
        dp[row][cola][colb]= chocolate[row][cola] ; chocolate[row][cola]= 0 ;
        dp[row][cola][colb]+=chocolate[row][colb] ;
        chocolate[row][cola]= tempa ;
        if(cola==0&& colb==m-1)return dp[row][cola][colb] ;
        else return dp[row][cola][colb]=-1000007 ;
    }
    else if(dp[row][cola][colb]!=-100007){
        return dp[row][cola][colb] ;
    }
    else{
        dp[row][cola][colb]= chocolate[row][cola] ;
        int tempa =chocolate[row][cola] ; chocolate[row][cola]=0 ;
        dp[row][cola][colb]+= chocolate[row][colb] ;
        chocolate[row][cola]= tempa ;
        int temper= -1000007 ;
        for(auto movea: movements){
            for(auto moveb: movements){
                if(valid(m,cola+movea,colb+moveb))temper= max(temper,memo(dp,chocolate,row-1,cola+movea,colb+moveb)) ;
            }
        }
        dp[row][cola][colb]+= temper ;
        
        return dp[row][cola][colb] ;
    }
}

int main(){
    int r,c ;
    cin>>r>>c ;
    vvii chocolate(r, vii(c,0)) ;
    for(int e=0 ;e<r ;e++)for(int f=0 ;f<c;f++)cin>>chocolate[e][f] ;
    int ans=0 ;
    vector<vvii> dp(r,vvii (c,vii(c,-100007))) ; //[row][cola][colb] 
    for(int e=0 ;e<c ;e++){
        for(int f=0 ;f<c ;f++){
            ans = max(ans,memo(dp,chocolate,r-1,e,f)) ;
        }
    }
    // for(int e=0 ;e<r ;e++){
    //     for(int f=0 ;f<c ;f++){
    //         cout<<"col a:-"<<f<<endl ;
    //         print(dp[e][f]) ;
    //     }
    //     cout<<endl ;
    // }
    cout<<ans<<endl ;
}