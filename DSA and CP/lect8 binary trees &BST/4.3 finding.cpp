#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define pob pop_back
//#define fir first 
//#define sec second
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vii;
typedef vector<vector<int>> vvii;

void print(vii& a){int n = a.size() ;for(int e=0 ;e<n ;e++)cout<<a[e] <<' ';cout<<endl ;}


class node {
    public:
    int val;
    node *left, *right;
    node(int a){
        val = a ;
        left=NULL ;
        right=NULL ;
    }
};

void insert(int h,node* &parent){
    if(parent==NULL){
        
        parent = new node(h) ;
        // cout<<parent->val<<" " ;
        return ;
    }
    if(parent->val <h){
        insert(h,parent-> right) ;
    }
    else{
        insert(h,parent-> left) ;
    }
}
bool find (int h ,node * root){
    if(root==NULL)return false ;
    if(root->val >h)return find(h,root->left) ;
    else if(root->val == h)return true ;
    else return find(h, root-> right) ;
}
int main(){
    int root ;
    cin>> root ;
    node * parent = new node(root) ;
    int numebr;
    cin>>numebr ;
    while(numebr--){
        int h ;
        cin>>h ;
        insert(h,parent) ;
    }
    preoder(parent) ;
}