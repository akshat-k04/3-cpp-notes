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

void preoder(node*root){
    if(root==NULL){
        return ;
    }
    /*
           1
          / \
         2   3
        / \ / \
       4  5 6  7 
    */
    // if this is tree we need to traversal(means navigate in full tree) like this 
    // 1 ,2 5, 6 , 3 , 7 , 8
    cout<<root->val<<" ";
    preoder(root->left) ;
    preoder(root->right) ;
    
}

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

void delte(int h , node* &parent){
    if(parent==NULL)return ;
    if(h>parent->val){
        delte(h,parent->right) ;
    }
    else if(h==parent->val){
        parent=NULL ;
    }
    else{
        delte(h,parent->left) ;
    }
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