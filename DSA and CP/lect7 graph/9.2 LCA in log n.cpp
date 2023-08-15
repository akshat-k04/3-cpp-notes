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

int primeInt2 = 1000000007 ;

//DSU

//trees

//graph

void dfs(int vertex,vvii & list,vii &parent){ // parent of top ost node is -1 so write it while declearing parent vector ,for rest write -2

    //case 1:- take action on vertex after entering the vertex

    for(auto child: list[vertex]){
        if(parent[child]!=-2)continue ;


        parent[child]=vertex ;

        // case 2:- take action on child before entering the child

        dfs(child,list,parent) ;

        // case 3:- take action on child after exiting the child
    }

    //case 4:- take action on vertex before exiting the vertex
}

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

//print it
void print(vii & a){for(int e=0 ;e<a.size() ;e++){cout<<a[e]<<" " ;}cout<<endl ;}
void printpair(vpii & a){for(int e=0 ;e<a.size() ;e++){cout<<a[e].first<<" "<<a[e].second<<endl ;}cout<<endl ;}

//solution here 

//0-indexed 
void fillancester(int root, vvii &list , vvii &ancesters){
// before calling  the function create this in main func
    // vvii ancesters ; 

    //initializing
    int n=list.size() ; // number of node
    int k = log2(n) +1 ;
    vii temp(k,-1) ;
    ancesters.assign(n,temp) ;
    vii parent(n,-2) ;parent[root]=-1 ;
    dfs(root,list,parent) ;


    // finding 2^i th ancester
    for(int e=0 ;e<n ;e++) ancesters[e][0]=parent[e] ;

    for(int e=1 ;e<k ;e++){

        for(int f=0 ;f<n ;f++){

            int prev =ancesters[f][e-1] ;
            if(prev!=-1)ancesters[f][e] =ancesters[prev][e-1] ;
        }
    }

}

int LCA(int root,int a,int b , vvii&ancesters,vvii&list){
    int n = ancesters.size() ;
    
    vii level(n,-1) ; // level means depth
    bfs(root,list,level) ;

    if(level[a]<level[b]){
        swap(a,b) ;
    }
    int diff = level[a]-level[b] ;
    // making a to same level

    while(diff>0){
        int i = log2(diff) ;
        a= ancesters[a][i];
        diff-=binpow(2,i,primeInt2) ;
    }

    if(a==b)return a ;
    int m = ancesters[0].size() ;// =log2(n)+1
    for (int i=m-1;i>=0;i--) {
        if (ancesters[a][i]!=-1 &&ancesters[a][i]!=ancesters[b][i]) {
            a=ancesters[a][i];
            b=ancesters[b][i];
        }
    }
    if (a!=b) return ancesters[a][0];
    else return a;
}



int main(){
    int node ;
    cin>>node ;
    int m;
    cin>>m;
    vvii list(n) ;
    for(int e=0 ;e<m;e++){
        int h,k;
        cin>>h>>k ;
        list[h].pb(k) ;
        list[k].pb(h) ;
    }
    
    
    vvii ancesters ; 
    fillancester(0,list,ancesters) ;

    int a,b ;
    cin>>a>>b ;
    cout<<LCA(0,a,b,ancester) ;
}