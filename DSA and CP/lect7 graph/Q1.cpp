//https://www.interviewbit.com/problems/path-with-good-nodes/
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

void dfs(int vertex,vvii & list,vii &parent,int &ans,vii &god,int &count,int lmt){ // parent of top ost node is -1 so write it while declearing parent vector ,for rest write -2

    //case 1:- take action on vertex after entering the vertex
    if(god[vertex]==1){
            // cout<<"J";

        count++ ;

    }
    for(auto child: list[vertex]){
        if(parent[child]!=-2)continue ;


        parent[child]=vertex ;

        // case 2:- take action on child before entering the child

        dfs(child,list,parent,ans,god,count,lmt) ;

        // case 3:- take action on child after exiting the child
    }
    if(list[vertex].size()==1 && list[vertex][0]==parent[vertex]){
        if(count<=lmt){

            ans++ ;
        }
    }
    if(god[vertex]==1){
        count-- ;
    }
    //case 4:- take action on vertex before exiting the vertex
}
void print(vii & a){for(int e=0 ;e<a.size() ;e++){cout<<a[e]<<" " ;}cout<<endl ;}


//solution here 

int solve(vii &a ,vvii &list,int limit){
    int n= a.size();
    int ans=0 ;
    vii parent(n,-2) ;parent[0]=-1 ;
    int count=0 ;
    dfs(0,list,parent,ans,a,count,limit) ;
    // print(parent);
    return ans ;
}

int main(){
    int n ;
    cin>>n ;
    vii a(n);
    for(int e=0 ;e<n ;e++)cin>>a[e] ;
    vvii list(n) ;
    for(int e=0 ;e<n-1;e++){
        int h ,k ;cin>>h>>k; h--;k--;
        list[k].pb(h);
        list[h].pb(k) ;
    }
    int c ;
    cin>>c ;
    cout<<solve(a,list,c) ;
}