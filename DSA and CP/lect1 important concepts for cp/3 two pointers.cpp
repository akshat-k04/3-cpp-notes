// Q link :- https://leetcode.com/problems/container-with-most-water/description/

/*
“The most effective techniques are those that are simple and well-executed,” in Data Structures and Algorithms, the two pointer technique is one of them.
Two Pointers is a pattern in which two pointers iterate across the Data Structure until one or both of them satisfy the necessary condition.

*/
#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define pob pop_back
#define fir first 
#define sec second
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

// number theory
//1. check prime
bool isprime(ll n){ // true if n is prime 
    if(n<=1){
        return false ;
    }
    else{
        for(ll e=2 ;e<sqrt(n);e++){
            if(n%e==0){
                return false ;
            } 
        }
        return true ;
    }
}

//2.binary exponentiation
ll binpow(ll a, ll b, ll m) { 
    //b=m-2 ;// if want to find the modular inverse 
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1){
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

//3.prime composite sieve
void primesieve(vii & a){
    // 0 means composite
    // 1 means prime 
    // 1 is not a prime nor composite but here we consider it as composite
    a[0]=0 ;
    a[1]=0 ;
    for(int e=2 ;e<=sqrt(a.size())+1 ;e++){
        if(a[e]==1){
            int f=e*e ;
            while(f<a.size()){
                a[f]=0 ;
                f+=e ;
            }
        }
    }
}

//4. prime factorization sieve and function
void primefactorsieve(vii & sieve){
    for(ll e=2 ;e<sieve.size();e++){
        if(sieve[e]==0){
            sieve[e]=e ;
            for(ll f=e*e ;f<sieve.size() ;f+=e){
                if(sieve[f]==0){
                    sieve[f]=e ;
                }
            }
        }
    }
}

void allfactors(int num,vii & sieve,vii &ans){
    while(num>1){
        ans.pb(sieve[num]) ;
        num/=sieve[num] ;
    }
}

//5. extended gcd
// a*x+b*y = gcd(a,b) , we find the integral value of x,y using function
// if a,b are co-prime then modular inverse of a = (x%b +b)%b  wrt b 
int extendedgcd(int a, int b, int& x, int& y) { //return value is gcd
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extendedgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

//6. factorial
void createFactorial(vll & factorial){
    factorial[0]=1 ;
    for(int e=1 ;e<factorial.size() ;e++){
        factorial[e] = (factorial[e-1]*e)  % primeInt2;
    }
}

ll combination(ll n,ll r,vll & factorial){
    ll ans = factorial[n] ;
    ll deno = factorial[n-r] * factorial[r] % primeInt2 ;
    ans = (ans* binpow(deno,primeInt2-2 ,primeInt2))  % primeInt2 ;
    return ans ;
}

//7. ETF
void etfsieve(vii &sieve){
    for(int e=0 ;e<sieve.size() ;e++){
        sieve[e]=e ;
    }
    for(int e=2 ; e<sieve.size();e++){
        if(sieve[e]==e){ //means it is prime
            sieve[e] = e-1 ;
            for(int f=2*e ;f<sieve.size();f+=e){
                sieve[f]/=e ;
                sieve[f]*=(e-1) ;
            }
        }
    }
}

//DSU

//trees

//graph

//Range Queries
 

//print it
void print(vii & a){for(int e=0 ;e<a.size() ;e++){cout<<a[e]<<" " ;}cout<<endl ;}
void printpair(vpii & a){for(int e=0 ;e<a.size() ;e++){cout<<a[e].first<<" "<<a[e].second<<endl ;}cout<<endl ;}

//solution here 

int solve(vii & a){
    vpii acopy ;
    int n = a.size() ;
    for(int e=0 ;e<n;e++){
        acopy.pb({a[e],e}) ;
    }
    sort(all(acopy)) ;
    int inipointer=0 ;
    int lstpointer=n-1 ;
    int ans=0 ;
    for(int e=0 ;e<n ;e++){
        while(inipointer<n &&a[inipointer]<acopy[e].first){
            inipointer++ ;
        }
        while(lstpointer>=0 &&a[lstpointer]<acopy[e].first){
            lstpointer--;
        }
        int temp = max(abs(inipointer-acopy[e].sec)*min(acopy[e].fir,a[inipointer]),abs(lstpointer-acopy[e].sec)*min(acopy[e].fir,a[lstpointer])) ;
        ans = max(ans,temp) ;
    }
    return ans ;
}

int main(){
    int n ;
    cin>>n ;
    vii a; 
    for(int e=0 ;e<n ;e++){
        int h ;
        cin>>h ;
        a.pb(h) ;
    }
    //input is done
    cout<<solve(a)<<endl ;
}