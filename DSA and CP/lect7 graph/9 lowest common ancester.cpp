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

void dfs(int vertex,vvii & list,vector<bool> &visited,int parent){
    if(visited[vertex]!=-2){
        return ;
    }
    visited[vertex]=parent ;
    //case 1:- take action on vertex after entering the vertex
    for(auto child: list[vertex]){
        // case 2:- take action on child before entering the child
        dfs(child,list,visited,vertex) ;
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
    vii visited(node,-2) ;
    dfs(0,list,visited,-1) ;
    int num1,num2 ;
    cin>>num1>>num2 ;
    vii parent1,parent2;
    while(num1>=0){
        parent1.pb(visited[num1]) ;
        num1=visited[num1] ;
    }
    while(num2>=0){
        parent2.pb(visited[num2]) ;
        num2=visited[num2] ;
    }
    reverse(all(parent1)) ;
    reverse(all(parent2)) ;
    int e=0 ;
    while(e<min(parent1.size(),parent2.size()) && parent1[e]==parent2[e]){
        e++ ;
    }
    if(e>0){
        e-- ;
    }
    cout<<parent1[e]<<endl ;// this is lca
}