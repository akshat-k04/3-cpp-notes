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

// void print(map<int,int>& a){int n = a.size() ;for(auto )cout<<a[e] <<' ';cout<<endl ;}

void dfs(int vertex,vvii & list,vii &parent,vector<map<int,int>> &store,vii &cost,int k){ // parent of top ost node is -1 so write it while declearing parent vector ,for rest write -2

    //case 1:- take action on vertex after entering the vertex

    for(auto child: list[vertex]){
        if(parent[child]!=-2)continue ;


        parent[child]=vertex ;

        // case 2:- take action on child before entering the child

        dfs(child,list,parent,store,cost,k) ;

        // case 3:- take action on child after exiting the child
    }

    store[vertex][cost[vertex]%k]++ ;
    for(auto child:list[vertex]){
        if(child==parent[vertex]) continue ;
        for(auto v : store[child]){
            store[vertex][(v.fir+cost[vertex])%k]+=v.sec ;
        }
    }

    //case 4:- take action on vertex before exiting the vertex
}

int main(){
    //input 
    int n ;cin>>n ;
    vii cost(n) ;
    for(int e=0 ;e<n ;e++)cin>>cost[e] ;

    vvii list(n) ;
    for(int e=0 ;e<n-1 ;e++){
        int h,k;
        cin>>h>>k ;
        list[h].pb(k) ;
        list[k].pb(h) ;
    }
    int k ;cin>>k ;

    // defining diff things 
    vector<map<int,int>> store(n) ;
    vii parent(n,-2) ; parent[0]=-1 ;
    dfs(0,list,parent,store,cost,k) ;


    //calculating ans
    int ans=0 ;
    for(int e=0 ;e<n ;e++)ans+=store[e][0] ;
    cout<<ans<<endl ;
}


