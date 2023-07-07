#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define pob pop_back
#define fir first 
#define sec second
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vii;
typedef vector<vector<int>> vvii;

//solution here 

bool dfs(int vertex,vvii & list,vector<bool> &visited,int parent){
    visited[vertex]=true ;
    //case 1:- take action on vertex after entering the vertex
    bool solved =false ;
    // cout<<vertex<<" ";
    for(auto child: list[vertex]){
        if(visited[child]&& child==parent){
            continue ;
        }
        if(visited[child]){
           solved=true ;
           return true ;
        }
        // case 2:- take action on child before entering the child
        solved |=dfs(child,list,visited,vertex) ;
        // case 3:- take action on child after exiting the child
    }
    return solved ;
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
    // for(int e=0 ;e<node)
    vector<bool> visited(node,false) ;
    int connectedcomp= 0 ;
    int solved = false ;
    for(int e=0;e<node;e++){
        if(!visited[e]){
        // cout<<e<<endl;

            connectedcomp++ ;
            solved|=dfs(e,list,visited,-1) ;
            // cout<<e<<endl ;
        }
    }
    cout<<solved<<endl ;
}

