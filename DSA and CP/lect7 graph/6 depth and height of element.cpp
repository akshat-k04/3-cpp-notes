/*
The highest node of the tree is called the root node.
A node that has no child is called a leaf node.
Any two nodes which are connected by an edge are called adjacent nodes.


Height
The height of a node is the number of edges on the longest path from that node to a leaf node.

As such, the height of the tree would be the height of its root node. Meanwhile, the leaf nodes have a height of 0.


Depth
The depth of a node is the number of edges from that node to the tree’s root node. As such, the depth of the whole tree would be the depth of its deepest leaf node. The root node has a depth of 0.

Let’s look at the following tree, which gives the depth of each node.
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

void dfs(int vertex,vvii & list,vector<bool> &visited,vii &height ,vii &depth){
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
    if(list[vertex].size()==1 && vertex!=0){ // assuming 0 is the root vertex
        height[vertex]=0 ;
    }
    else{
        for(auto child:list[vertex]){
            height[vertex]=max(height[vertex],height[child]+1) ;
        }
    }
    //case 4:- take action on vertex before exiting the vertex
}

int main(){
    int n ;
    cin>>n ;
    vii height(n),depth(n) ;
    int edge ;
    cin>>edge ;
    vvii list(n) ;
    for(int e=0 ;e<edge;e++){
        int h,k ;
        cin>> h>>k ;
        list[h].pb(k) ;
        list[k].pb(h) ;
    }
    vii visited(n);
    depth[0]=0 ;
    dfs(0,list,visited,height,depth) ;
}