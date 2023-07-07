/*

here we use deque it is data structure in which we can add element in front also
we can remove from front using pop_front() 
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


void bfs(int vertex,vvii &list,vii &level){
    level[vertex]=0 ;
    queue<int> que ;
    que.push(vertex);

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

//Range Queries
 

//print it
void print(vii & a){for(int e=0 ;e<a.size() ;e++){cout<<a[e]<<" " ;}cout<<endl ;}
void printpair(vpii & a){for(int e=0 ;e<a.size() ;e++){cout<<a[e].first<<" "<<a[e].second<<endl ;}cout<<endl ;}

//solution here 
int primeInt2=1000000007 ;
void zero1bfs(int vertex,vector<vpii> & list ,vii &level){
    deque<int> q ;
    level[vertex]= 0  ;
    q.pb(vertex) ;
    while(q.size()!=0){
        vertex=q.front() ;
        q.pop_front() ;
        for(auto child:list[vertex]){
            if(level[child.fir]!=primeInt2)continue ;

            if(child.sec==0)q.push_front(child.fir) ;
            else q.push_back(child.fir) ;
            level[child.fir]=level[vertex]+child.sec ;
        }
    }
}

int main(){
    int node ;
    cin>>node ;
    vector<vpii> list(node) ;
    // her we also add weight of edge in the list 
    int edge ;
    cin>>edge ;
    for(int e=0 ;e<edge ;e++){
        int a,b ;
        cin>>a>>b ;
        int weight ;
        cin>>weight ;
        list[a].pb({b,weight}) ;
        list[b].pb({a,weight}) ;
    }
    vii level(node,1000000007) ; //level denotes the distance from the node 0
    zero1bfs(0,list,level) ;
    print(level) ;
}