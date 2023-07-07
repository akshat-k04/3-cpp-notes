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

const ll largestLL= 1e18;
const int largestI = 1e9;
const ll primeInt2 = 1000000007;
const int primeInt = 998244353;




/*inbuilt functions:-
1.gcd :- __gcd(a,b)
2.to convert int to string to_string(number)
3.to convert char to int we have to handle it mannually int a = '6' - '0' 
4.queue<int>, stack<int> --> has push() ,pop() , front() for queue ,top() for stack , 
5.reverse(a.begin() , a.end())
6.st.erase(st.begin()+index) or st.erase(st.begin()+iniIndex , st.begin() + lstIndex)// note that lst index will not erase it is similar to open bracket 
7.upper_bound(a.begin(),a.end(),5):- smallest that is greater then 5
8.lower_bound(a.begin(),a.end(),5):- greater than or equals to the 5
9. if the vector is in decreasing order then we use a.rbegin() , a.rend() 
*/

//functions
//all prime till a
//vector<int> prime(100001,1) ;
//1 means prime
//void sieve(int a){
//    for(int e=2 ; e<=a ;e++){
//        if(prime[e]==1 &&e*e<=a){
//            for(int p=e*e ;p<=a ;p+=e){
//                 prime[p]=0 ;
//            }
//        }
//    }
//    for(int e=2  ; e<=a ;e++){
//        if(prime[e]==1){
//            cout<<e<<" ";
//        }
//    }
//}

//check prime (true means prime )
bool checkPrime(int a){
    int b = sqrt(a) ;
    for(int e=2 ; e<=b ;e++){
        if(a%b==0){
            return false ; // means it is not prime
        }
    }
    return true ;
}

void print(vii & a){
    for(int e=0 ;e<a.size() ;e++){
        cout<<a[e]<<setw(1) ;
    }
    cout<<endl ;
}

//solution here 

struct node {
    int data ;
    struct node * left ;
    struct node * right ;

    node(int val){
        data = val ;
        left=NULL ;
        right =NULL ;
    }
};

void bfs(queue<struct node *>& queu){
    struct node * temp = queu.front() ;
    while(queu.size()!=0){
        vector<struct node *> temp ;
        while(queu.size()!=0){
            cout<<queu.front()->data<<" ";
            if(queu.front()->left!=NULL){
                temp.pb(queu.front()->left) ;
            }
            if(queu.front()->right!=NULL){
                temp.pb(queu.front()->right) ;
            }
            queu.pop() ;
        }
        for(int e=0 ;e<temp.size();e++){
            if(temp[e]!=NULL){
                queu.push(temp[e]) ;
            }
        }
    }

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
    queue<struct node *> queu ;
    queu.push(root) ;
    bfs(queu) ;
}