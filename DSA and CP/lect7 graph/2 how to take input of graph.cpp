/*
we get as n as a input which tells the number of nodes
          q as a input which tells the number of edges
          now next q line we get a,b as input which represents the vertex of with which edge is connected


how we store it??
so we make vvii list(n+1) ; this contain all connected vertex of p in list[p]
Now do what you want

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

//solution here 


int main(){
    int nodes ;
    cin>>nodes ;
    int edges ;
    cin>>edges ;
    vvii list(n+1) ;
    for(int e=0 ;e<edges;e++){
        int h,k ;
        cin>>h>>k ;
        list[h].pb(k) ;
        list[k].pb(h) ;
    }
    // done now do what you want
}