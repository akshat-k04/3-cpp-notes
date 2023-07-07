//done

/*
Given a matrix of integers A of size N x M in which each row is sorted.

Find and return the overall median of matrix A.

NOTE: No extra memory is allowed.

NOTE: Rows are numbered from top to bottom and columns are numbered from left to right.



Problem Constraints
1 <= N, M <= 10^5

1 <= N*M <= 10^6

1 <= A[i] <= 10^9

N*M is odd



Input Format
The first and only argument given is the integer matrix A.



Output Format
Return the overall median of matrix A.



Example Input
Input 1: 

A = [   [1, 3, 5],
        [2, 6, 9],
        [3, 6, 9]   ] 
Input 2: 

A = [   [5, 17, 100]    ]


Example Output
Output 1: 

 5 
Output 2: 

 17


Example Explanation
Explanation 1: 

A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
Median is 5. So, we return 5. 
Explanation 2:

Median is 17.
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

int check(vvii &a , int &l){
    // cout<<l<<" p";
    int countergreater=0 ;
    int counterlesser=0 ;
    int counterequal=0 ;
    for(int e=0 ;e<a.size() ; e++){
        int one = (upper_bound(a[e].begin() , a[e].end(),l) -a[e].begin()) ;
        
        int two = (lower_bound(a[e].begin() , a[e].end(),l) -a[e].begin()) ;
        countergreater+= (a[e].size()-one) ;
        // cout<<two<<" q";
        counterlesser+= two ;
        counterequal+=(one-two) ;
    }
    // cout<<endl ;
    if(counterequal!=0){counterequal-- ;}
    // cout<<countergreater<<counterlesser<<counterequal<<endl ;
    if(abs(countergreater-counterlesser)<=counterequal){
        //  cout<<"YO"<<endl ;
        return 0 ;
    }
    else {
        if(countergreater>counterlesser){
            return -1 ;
        }
        else{
            return 1 ;
        }
    }
}

int main(){
    int n,m ;
    cin>>n>>m ;
    vvii a ;
    for(int e=0 ;e<n ; e++){
        vii temp ;
        for(int f= 0; f<m; f++){
            int h ;
            cin>>h ;
            temp.pb(h) ;
        }
        a.pb(temp) ;
    }
    //input is done
    int minnotpossible =0;
    int ini=0 ;
    int lst =1000000 ;
    int mid ;
    while(lst-ini>1){
        mid = (ini+lst)/2 ;
        int lrt =check(a,mid) ;
        if(lrt==-1){
            ini =mid ;
        }
        else if(lrt==0){
            cout<< mid ;
            break ;
        }
        else {
            lst = mid ;
        }
    }
    
}