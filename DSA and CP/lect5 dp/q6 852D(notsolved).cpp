// In winter, the inhabitants of the Moscow Zoo are very bored, in particular, it concerns gorillas. You decided to entertain them and brought a permutation p
//  of length n
//  to the zoo.

// A permutation of length n
//  is an array consisting of n
//  distinct integers from 1
//  to n
//  in any order. For example, [2,3,1,5,4]
//  is a permutation, but [1,2,2]
//  is not a permutation (2
//  occurs twice in the array) and [1,3,4]
//  is also not a permutation (n=3
// , but 4
//  is present in the array).

// The gorillas had their own permutation q
//  of length n
// . They suggested that you count the number of pairs of integers l,r
//  (1≤l≤r≤n
// ) such that MEX([pl,pl+1,…,pr])=MEX([ql,ql+1,…,qr])
// .

// The MEX
//  of the sequence is the minimum integer positive number missing from this sequence. For example, MEX([1,3])=2
// , MEX([5])=1
// , MEX([3,1,2,6])=4
// .

// You do not want to risk your health, so you will not dare to refuse the gorillas.

// Input
// The first line contains a single integer n
//  (1≤n≤2⋅105
// ) — the permutations length.

// The second line contains n
//  integers p1,p2,…,pn
//  (1≤pi≤n
// ) — the elements of the permutation p
// .

// The third line contains n
//  integers q1,q2,…,qn
//  (1≤qi≤n
// ) — the elements of the permutation q
// .

// Output
// Print a single integer — the number of suitable pairs l
//  and r
// .
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

//solution here 

void generate(vii & p , vii & q){
    int n = p.size() ;
    vii posip(n+1),posiq(n+1) ;
    for(int e=0 ;e<n ;e++){
        posip[p[e]]=e ;
        posiq[q[e]] =e ;
    }
    //we get the posi
    ll ans=0 ;
    int min = n+1 ;
    int max = -1 ;
    for(int e=1 ;e<=n ;e++){
        min = min(min ,min(posip[e],posiq[e])) ;
        max = max(max,max(posip[e],posiq[e])) ;
        
    }
}

int main(){
    int t ;
    cin>>t ;
    for(int r=0 ;r<t ;r++){
        int n ;
        cin>>n ;
        vii p(n) ;
        for(int e=0 ;e<n ;e++){
            cin>>p[e] ;
        }
        vii q(n) ;
        for(int e=0 ;e<n ;e++){
            cin>>q[e] ;
        }
        //input is done
        generate(p,q) ;
    }
}