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

//graph

void dfs(int vertex,vvii & list,vector<int> &visited,int parent,vii & depth){
    if(visited[vertex]!=-2){
        return ;
    }
    visited[vertex]=parent ;
    //case 1:- take action on vertex after entering the vertex
    for(auto child: list[vertex]){
        // case 2:- take action on child before entering the child
        depth[child]=depth[vertex]+1 ;
        dfs(child,list,visited,vertex,depth) ;
        // case 3:- take action on child after exiting the child
    }
    //case 4:- take action on vertex before exiting the vertex
}

//Range Queries
 

//print it
void print(vii & a){for(int e=0 ;e<a.size() ;e++){cout<<a[e]<<" " ;}cout<<endl ;}
void printpair(vpii & a){for(int e=0 ;e<a.size() ;e++){cout<<a[e].first<<" "<<a[e].second<<endl ;}cout<<endl ;}

//solution here 


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
    vii visited(node,-2) ; // stores the parent num also
    vii depth(node,0) ;
    dfs(0,list,visited,-1,depth) ;
    int num1,num2 ;
    cin>>num1>>num2 ;
    if(depth[num1]>depth[num2]){
        swap(num1,num2) ;
    }
    int diff = depth[num2]-depth[num1] ;
    while(diff){
        num1=visited[num1] ;
        diff-- ;
    }
    if(num1==num2){
        cout<<num2<<endl ;
    }
    else{
        while(visited[num1]!=visited[num2]){
            num1=visited[num1] ;
            num2=visited[num2] ;
        }
        cout<<visited[num1]<<endl ;
    }
}