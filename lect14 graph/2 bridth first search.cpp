// here we write a algo to find which nodes are connected and which are not

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

const ll largestLL= 1e18;
const int largestI = 1e9;
const ll primeInt2 = 1000000007;
const int primeInt = 998244353;

/*inbuilt functions:-
gcd :- __gcd(a,b)
to convert int to string to_string(number)
to convert char to int 
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

//solution here 
int n ; //no. of edges
int  ki ; //no. of node
void bfs(vector<vii> &store,vii &visited){
    queue<int> que ;
    que.push(1) ;
    visited[1]=1 ;
    while(que.size()!=0){
        for(int e=0 ;e<store[que.front()].size() ; e++){
            if(visited[store[que.front()][e]]==0){
                que.push(store[que.front()][e]) ;
                visited[store[que.front()][e]] =1 ;
            }
        }
        que.pop() ;
    }
}

int main(){
    cin>> n ; // no. of edges
    
    cin>>ki ; //no. of node
    vii visited ;
    for(int e=0 ;e<=ki ; e++){
        visited.pb(0) ;
    }
    vector<pair<int,int>> a ;
    int h,k ;
    for(int e=0 ;e<n ;e ++){
        cin>>h ;
        cin>>k ;
        a.pb({h,k}) ;
    }
    // we get all edge 
    // now its time to make the vector where we store the vector which store the number 
    vector<vii> store(ki+1) ;
    for(int e=0;e<n;e++){
        store[a[e].first].pb(a[e].second) ;
        store[a[e].second].pb(a[e].first) ;
    }
    //we store a graph 
    //now its time to do bfs 
    bfs(store,visited) ;
    for(int e=1 ; e<=ki ; e++){
        cout<<visited[e]<<" "<<e<<endl ;
    }
}