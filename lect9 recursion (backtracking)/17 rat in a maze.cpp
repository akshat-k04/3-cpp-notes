/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.
Your Task:  
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order. 
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((3N^2)).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

Constraints:
2 ≤ N ≤ 5
0 ≤ m[i][j] ≤ 1
*/

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
gcd :- __gcd(a,b)
to convert int to string to_string(number)
to convert char to int we have to handle it mannually int a = '6' - '0' 
queue<int>, stack<int> --> has push() ,pop() , front() for queue ,top() for stack , 
reverse(a.begin() , a.end())
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

void generate(vector<string> & ans , vvii & m , int row ,int col,string &s){
    int n = m.size() ;
    // cout<<row<<" "<<col<<endl ;
    if(row==n-1 && col==n-1){
        // cout<<"hello"<<endl ;
        ans.pb(s);
        return ;
    }
    if(row<n-1 && m[row+1][col]==1){
        s+='D' ;
        m[row+1][col]=0 ;
        generate(ans,m,row+1 , col,s) ;
        m[row+1][col]=1 ;
        s.pob() ;
    }
    if(col<n-1 && m[row][col+1]==1){
        s+='R' ;
        m[row][col+1]=0 ;
        generate(ans,m,row , col+1,s) ;
        m[row][col+1]=1;
        s.pob() ;
    }
    if(row>0 &&m[row-1][col]==1){
        s+='U' ;
        m[row-1][col]=0 ;
        generate(ans,m,row-1 , col,s) ;
        m[row-1][col]=1 ;
        s.pob() ;
    }
    if(col>0 && m[row][col-1]==1){
        s+='L' ;
         m[row][col-1]=0 ;
        generate(ans,m,row , col-1,s) ;
         m[row][col-1]=1 ;
        s.pob() ;
    }
}

int main(){
    int n ;
    cin>>n ;
    vvii m ;
    int h ;
    for(int e=0 ;e<n ;e++){
        vii temp ;
        for(int f=0 ;f<n ;f++){
            cin>>h ;
            temp.pb(h) ;
        }
        m.pb(temp) ;
    }
    //input is done
    vector<string> ans ;
    string s ;
    if(m[0][0]==1){
        m[0][0]=0 ;
        generate(ans , m,0,0,s) ;
    }

    
    
    for(int e=0 ;e<ans.size() ; e++){
        cout<<ans[e]<<endl ;
    }
}