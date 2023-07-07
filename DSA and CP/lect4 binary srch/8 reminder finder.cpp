 //done



// Implement pow(x, n) % d.
// In other words, given x, n and d,
// Find (xn % d)
// Note that remainders on division cannot be negative. In other words, make sure the answer you return is non-negative integer.


// Problem Constraints
// -109 <= x <= 109
// 0 <= n <= 109
// 1 <= d <= 109


// Example Input
// Input 1:
// x = 2
// n = 3
// d = 3
// Input 2:
// x = 5
// n = 2
// d = 6


// Example Output
// Output 1:
// 2
// Output 2:
// 1


// Example Explanation
// Explanation 1:
// 23 % 3 = 8 % 3 = 2.
// Explanation 2:
// 52 % 6 = 25 % 6 = 1.


#include <bits/stdc++.h>
#include <cmath>
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


int main(){
    ll n,x,d ;
    cin>>x>>n>>d ;
    vll storage ;
    ll counter=0 ;
    ll temper = x%d ;
    temper+=d ;
    temper%=d ;
    storage.pb(temper) ;
    while(pow(2,counter)<1000000005){
        counter++ ;
        temper*=temper ;
        temper%=d ;
        storage.pb(temper) ;
    }
    ll reminder=1 ;
    int ncopy = n ;
    // input is done 
    while(ncopy!=0){
        int fac = log2(ncopy) ;
        reminder*=storage[fac] ;
        reminder%=d ;
        ncopy-=pow(2,fac) ;
    }
    cout<<reminder<<endl ;
}