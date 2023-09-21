// https://cses.fi/problemset/task/1633

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

int main(){
    int n ;cin>>n ;
    vector<int> tabu(n+1) ; tabu[1]=1 ;tabu[2]=2 ;
    for(int e=3 ;e<=min(6,n);e++){
        for(int f=1 ;f<e ;f++){
            tabu[e]+=tabu[f] ;
        }
        tabu[e]++ ;
    }
    for(int e=7 ;e<=n ;e++){
        for(int f=e-6 ;f<e ;f++){
            tabu[e]+= tabu[f] ;
            tabu[e]%=1000000007 ;
        }

    }
    cout<<tabu[n] <<endl ;
}