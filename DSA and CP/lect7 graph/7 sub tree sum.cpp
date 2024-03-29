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

void dfs(int vertex,vvii & list,vector<bool> &visited,vii&subtreesum){
    if(visited[vertex]){
        return ;
    }
    visited[vertex]=true ;
    //case 1:- take action on vertex after entering the vertex
    for(auto child: list[vertex]){
        // case 2:- take action on child before entering the child
        dfs(child,list,visited,subtreesum) ;
        // case 3:- take action on child after exiting the child
    }
    subtreesum[vertex]=vertex ;
    for(auto child:vertex){
        subtreesum[vertex]+=subtreesum[child] ;
    }
    //case 4:- take action on vertex before exiting the vertex
}


int main(){
    int node ;
    cin>>node ;
    int edge ;
    cin>>edge ;
    vvii list(node) ;
    for(int e=0 ;e<edge;e++){
        int h,k ;
        cin>>h>>k ;
        list[h].pb(k) ;
        list[k].pb(h) ;
    }
    vector<bool> visited(node,false) ;
    subtreesum(n) ;
    dfs(0,list,visited,subtreesum) ;
    // we get the sum of sub tree whose vertex is i (belong to 0 to n-1)
     
}