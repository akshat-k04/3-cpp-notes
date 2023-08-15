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

void print(vii& a){int n = a.size() ;for(int e=0 ;e<n ;e++)cout<<a[e] <<' ';cout<<endl ;}

int isprime(int a){
    if (a==1) return false;
    for(int e=2 ;e<a ;e++){
        if(a%e==0)return false ;
    }
    return true ;
}

void dfs(int vertex,vvii & list,vii &parent,vvii &facs,int &ans){ // parent of top ost node is -1 so write it while declearing parent vector ,for rest write -2

    //case 1:- take action on vertex after entering the vertex

    for(auto child: list[vertex]){
        if(parent[child]!=-2)continue ;


        parent[child]=vertex ;

        // case 2:- take action on child before entering the child

        dfs(child,list,parent,facs,ans) ;

        // case 3:- take action on child after exiting the child
    }

    // creating the facs array
    facs[vertex][isprime(vertex+1)]++ ;
    for(auto child:list[vertex]){
        if(parent[vertex]==child)continue ;
        if(isprime(vertex+1)){
            facs[vertex][1]+= facs[child][0] ;
        }
        else{
            facs[vertex][0]+= facs[child][0] ;
            facs[vertex][1]+= facs[child][1] ;
        }
    }


    /// adding to answer 
    //1 using seperate child
    for(auto child:list[vertex]){
        if(parent[vertex]==child)continue ;
        ans+= facs[child][!isprime(vertex+1)] ;
    }

    //2 intermixing the child
    int temper=0 ;
    for(auto child: list[vertex]){
        if(parent[vertex]==child)continue ;
        if(isprime(vertex+1)){
            temper+= facs[child][0]*(facs[vertex][1]-facs[child][0]-1) ;
        }
        else{
            temper+= facs[child][0]*(facs[vertex][1]-facs[child][1]) ;
            temper+= facs[child][1]* (facs[vertex][0]-facs[child][0]-1) ;
        }
    }
    temper/=2 ;
    ans+=temper ;

    //case 4:- take action on vertex before exiting the vertex
}

int main(){
    int n ;cin>>n ;
    vvii list(n) ;
    for(int e=0 ;e<n-1 ;e++){
        int h,k ;
        cin>>h>>k ;
        list[h].pb(k) ;
        list[k].pb(h) ;
    }
    vvii facs(n,vii (2,0)) ; vii parent(n,-2) ;parent[0]=-1 ;
    int ans =0 ;
    dfs(0,list,parent,facs,ans) ;
    cout<<ans<<endl ;
}


