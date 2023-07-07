//done

/*
Given 2 integers A and B and an array of integers C of size N. Element C[i] represents the length of ith board.
 You have to paint all N boards [C0, C1, C2, C3 … CN-1]. There are A painters available and each of them takes B units of time to paint 1 unit of the board.

Calculate and return the minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of the board.
 NOTE: 
 1. 2 painters cannot share a board to paint. That is to say, a board cannot be painted partially by one painter, and partially by another.
 2. A painter will only paint contiguous boards. This means a configuration where painter 1 paints boards 1 and 3 but not 2 is invalid.

 Return the ans % 10000003.



Problem Constraints
1 <= A <= 1000

1 <= B <= 106

1 <= N <= 105

1 <= C[i] <= 106



Input Format
The first argument given is the integer A.

The second argument given is the integer B.

The third argument given is the integer array C.



Output Format
Return minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of board % 10000003.



Example Input
Input 1:

 A = 2
 B = 5
 C = [1, 10]
Input 2:

 A = 10
 B = 1
 C = [1, 8, 11, 3]


Example Output
Output 1:

 50
Output 2:

 11


Example Explanation
Explanation 1:

 Possibility 1:- One painter paints both blocks, time taken = 55 units.
 Possibility 2:- Painter 1 paints block 1, painter 2 paints block 2, time take = max(5, 50) = 50
 There are no other distinct ways to paint boards.
 ans = 50 % 10000003
Explanation 2:

 Each block is painted by a painter so, Painter 1 paints block 1, painter 2 paints block 2, painter 3 paints block 3 
 and painter 4 paints block 4, time taken = max(1, 8, 11, 3) = 11
 ans = 11 % 10000003
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

int people(int workers,vii& c , ll maxlength , ll maxvalue){
    // cout<<maxvalue<<endl ;
    if(maxvalue<maxlength){
        return (workers+1) ;
    }
    else{
        int n=c.size() ;
        int workercouneter=0 ;
        for(int e=0 ; e<n ;){
            int lencounter=0 ;
            while(lencounter<=maxvalue && e<n){
                lencounter+=c[e] ;
                e++ ;
            }
            if(lencounter>maxvalue){
                e-- ;
                lencounter-=c[e] ;
            }
            workercouneter++;
        }
        return workercouneter ;
    }
}

int main(){
    int a,b;
    cin>>a>>b ;
    // a= number of workers 
    //b= time needed to paint 1 tile
    vii c ;
    int n ;
    cin>>n ;
    for(int e=0 ;e<n ;e++){
        int h ;
        cin>>h ;
        c.pb(h) ;
    }

    //input is done;
    int maxi=0 ;
    for(int e= 0 ;e<n ;e ++){
        maxi=max(maxi,c[e]) ;
    }
    ll ini=0 ;
    ll lst = 100000000005 ;
    ll mid ;
    while(lst-ini>1){
        mid=(ini+lst)/2 ;
        if(people(a,c,maxi,mid)>a){
            ini=mid ;
        }
        else{
            lst=mid;
        }
    }
    cout<<b*lst <<endl ;
}