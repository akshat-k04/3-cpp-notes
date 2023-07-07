/*
dijkstra is used to find the shortest dist of all the node from the source
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
// vii dist(n,1000000007) ; write this in main func
// list contain node and weight of edge connecting node and parent node
void dijkstra(int vertex,vector<vpii>&list,vii&dist){
    int n=list.size() ;
    vii visited(n) ;

    set<pair<int,int>> que ; // weight,node

    //inserted the first element from where need to find the mini dist
    que.insert({0,vertex}) ;
    dist[vertex]=0 ;
    while(que.size()!=0){
        vertex = (*que.begin()).sec ;
        int length = (*que.begin()).fir ;//dist till this vertex
        que.erase(que.begin()) ;

        if(visited[vertex]==1)continue ;
        visited[vertex]=1 ;
        
        for(auto child:list[vertex]){
            
            if(length+child.sec<dist[child.fir]){
                dist[child.fir]=length+child.sec ;
                que.insert({dist[child.fir],child.fir}) ;
            }
        }
    }
}

int main(){
    int node; 
    cin>>node ;
    int edge ;
    cin>>edge ;
    vector<vpii> list(node) ;// here i store the node with weight of edge

    for(int e=0 ;e<edge;e++){
        // the edge is directed the add in list accordingly
        int h,k,weight ;
        cin>>h>>k>>weight ;
        list[h].pb({k,weight}) ;// means we go from h to k
        list[k].pb({h,weight}) ;// we go from k to h
    }
    int source ;
    cin>>source;
    vii dist(node,1000000007) ;
    dijkstra(source,list,dist) ;
    print(dist) ;
}