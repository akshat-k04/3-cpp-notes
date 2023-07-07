/*
The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two leaves in the tree.

to find this we first find the depthest element from on one element now that depthest element is the on of the end of diameter
now again find depthest element from this element

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


//print it
void print(vii & a){for(int e=0 ;e<a.size() ;e++){cout<<a[e]<<" " ;}cout<<endl ;}
void printpair(vpii & a){for(int e=0 ;e<a.size() ;e++){cout<<a[e].first<<" "<<a[e].second<<endl ;}cout<<endl ;}

//solution here 

void dfs(int vertex,vvii & list,vector<bool> &visited,vii &depth){
    if(visited[vertex]){
        return ;
    }
    visited[vertex]=true ;
    //case 1:- take action on vertex after entering the vertex
    for(auto child: list[vertex]){
        // case 2:- take action on child before entering the child
        depth[child]=depth[vertex]+1 ;
        dfs(child,list,visited) ;
        // case 3:- take action on child after exiting the child
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
    vii depth(node) ;
    dfs(0,list,visited,depth) ;
    int maxnode=-1 ;
    int maxdepth=-1 ;
    for(int e=0;e<node;e++){
        if(maxdepth<depth[e]){
            maxnode=e ;
            maxdepth=depth[e] ;
        }
        visited[e]=false ;
        depth[e]=0 ;
    }
    dfs(maxnode,list,visited,depth) ;
    sort(all(depth)) ;
    cout<<depth[node-1] <<endl ;//this is the length of diameter
}