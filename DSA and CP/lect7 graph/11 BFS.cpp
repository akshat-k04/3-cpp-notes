/*
the benefit of bfs is that we can find the shortest from the root to 
every node the level represent the length
*/

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
void print(vii & a){for(int e=0 ;e<a.size() ;e++){cout<<a[e]<<" " ;}cout<<endl ;}

//solution here 

void bfs(int vertex,vvii &list,vii &level){
    level[vertex]=0 ;
    queue<int> que ;
    que.push(vertex) ;
    while(que.size()!=0){
        vertex=que.front() ;
        que.pop() ;
        for(auto child:list[vertex]){
            if(level[child]!=-1)continue ;
            que.push(child) ;
            level[child]=level[vertex]+1 ;
        }
    }
}

int main(){
    int node ;
    cin>>node ;
    vvii list(node) ;
    for(int e=0 ;e<node-1;e++){
        int h,k ;
        cin>>h>>k ;
        list[h].pb(k) ;
        list[k].pb(h) ;
    }
    vii level(node,-1) ;
    bfs(0,list,level) ;
    print(level) ;
}