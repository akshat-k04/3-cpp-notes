/*
i have an array 
i have to do q operation wheather it is of updating 
the index of finding the  sum of sub arry from i to j
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


void built(int indx,int ini,int end ,vii&tree ,vii & a){
    // in main func make  vii tree(4*a.size()) ;
    //then run func as built(1,0,n-1,tree,a);
    if(ini==end)tree[indx]=a[ini] ;
    else{
        int mid =ini+end ;mid/=2 ;
        built(2*indx,ini,mid ,tree,a) ;
        built(2*indx+1,mid+1,end,tree,a) ;

//depends on question
        tree[indx]=tree[2*indx]+tree[2*indx+1] ;
    }
}

int query(int l,int r ,vii&tree,int ini ,int end,int node){
    // call query like this query(l,r,tree,0,n-1,1) ; in main func

    if(l>end||r<ini){
//depends on question
        return  0 ; 
    }
    if(l<=ini && end<=r){
        // the range ini to end completely overlap on query
        return tree[node] ;
    }
    else {
        int mid =(ini+end)/2 ;
//depends on question
        return query(l,r,tree,ini,mid,2*node)+query(l,r,tree,mid+1,end,2*node+1) ;
    }
}

void updateIndx(int ini,int end,int node,vii&tree,int indx,int val,vii&a){
//write this in main func:- updateIndx(0,n-1,1,tree,indx,val);

    if(ini==end){
        tree[node]=val ;
        a[indx]=val ; // just for tp no relation with this code
        return ;
    }
    if(ini<=indx && indx<=end){
        int mid =(ini+end)/2 ;
        updateIndx(ini,mid,2*node,tree,indx,val,a) ;
        updateIndx(mid+1,end,2*node+1,tree,indx,val,a) ;

//depends on question
        tree[node]=tree[2*node]+tree[2*node+1] ; 
    }
    return ;
}


int main(){
    int n ;
    cin>> n ;
    vii a(n) ;
    for(int e=0 ;e<n ;e++)cin>>a[e] ;
    vii tree(4*n) ;
    built(1,0,n-1,tree,a) ;
    int q ;
    cin>>q ;
    // print(tree) ;
    for(int e= 0;e<q;e++){

        int g ;
        cin>>g ;
        
        
        if(g==1){
            int ind ,val ;
            cin>> ind>>val ;
            ind-- ;
            updateIndx(0,n-1,1,tree,ind,val,a);
        }
        else{
            int ini,end ;
            cin>>ini>>end; ini--;end-- ;
            cout<<query(ini,end,tree,0,n-1,1)<<endl  ;
        }
    }
}