//pre order traversal (root left right)

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


//solution here 
struct node {

        int data ;
        struct node *left ; // this is a pointer of a struct (node) ;
        struct node*right ;

        node(int val){ // constructor
            data=val ;
            left =NULL ;
            right=NULL;
        }
    } ;

void preoder(struct node*root){
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
    cout<<root->data <<" ";
    preoder(root->left) ;
    preoder(root->right) ;
    
}


int main(){
    struct node * root= new node(1) ;
    root->left = new node(2) ;
    root-> right= new node(3) ;
    /*
         1
        / \
       2   3
    */
    root->left->left = new node(4) ;
    root->left->right = new node(5) ;
    root->right->left = new node(6) ;
    root->right->right = new node(7) ;
    /*
           1
          / \
         2   3
        / \ / \
       4  5 6  7 
    */
    preoder(root) ;
}