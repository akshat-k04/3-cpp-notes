//https://www.interviewbit.com/problems/delete-edge/

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


void dfs(int vertex,vvii & list,vii &parent,vii &subtreesum ,vii&weightnode){ // parent of top ost node is -1 so write it while declearing parent vector ,for rest write -2
    //case 1:- take action on vertex after entering the vertex

    for(auto child: list[vertex]){
        if(parent[child]!=-2)continue ;


        parent[child]=vertex ;

        // case 2:- take action on child before entering the child

        dfs(child,list,parent,subtreesum,weightnode) ;
        // case 3:- take action on child after exiting the child
    }
    subtreesum[vertex]= weightnode[vertex] ;
    for(auto child : list[vertex]){
        subtreesum[vertex]+=subtreesum[child] ;
    }
    //case 4:- take action on vertex before exiting the vertex
}

//Range Queries
 

//print it
void print(vii & a){for(int e=0 ;e<a.size() ;e++){cout<<a[e]<<" " ;}cout<<endl ;}
void printpair(vpii & a){for(int e=0 ;e<a.size() ;e++){cout<<a[e].first<<" "<<a[e].second<<endl ;}cout<<endl ;}

//solution here 

int solve(vii weightnode,vvii list){
    int n = weightnode.size() ;
    // root node is one 
    // lets find the sum of all the sub trees 
    vii subtreesum(n) ;
    vii parent(n,-2) ;parent[0]=-1 ;
    dfs(0,list,parent,subtreesum,weightnode) ;
    ll ans= 0;
    for(int e=0 ;e<n ;e++){
        ll temp = 1LL*subtreesum[e]*(subtreesum[0]-subtreesum[e]) ;
        if(temp>ans)ans=temp ;
    }
    return (ans%(1000000007)) ;
}

int main(){
    int n ;
    cin>> n;
    vii weightnode(n) ;
    for(int e=0 ;e<n ;e++){
        cin>>weightnode[e] ;
    }
    vvii list(n) ;
    for(int e=0; e<n-1 ;e++){
        int h,k ;cin>>h>>k ;h--;k--;
        list[h].pb(k) ;
        list[k].pb(h) ;
    }
    cout<<solve(weightnode,list) <<endl ;
}