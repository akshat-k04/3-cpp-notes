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

int fibonachii(int n , int store){
    if(n<=2)return n+1 ;

    int a = store[n-1];
    int b = store[n-2] ;
    if(a==-1)a=fibonachii(n-1,store) ;
    if(b==-1) b = fibonachii(n-2,store) ;
    return a+b ;
}

int main(){
    vii store (100007,-1) ;
    int k ;
    cin>>k ;
    if(store[k+1]==-1){
        cout<<fibonachii(k+1,store)<<endl  ;
    }
}