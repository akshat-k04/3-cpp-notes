//not solved

// You are given an array a
//  consisting of n
//  integers.

// You have to perform the sequence of n−2
//  operations on this array:

// during the first operation, you either add a2
//  to a1
//  and subtract a2
//  from a3
// , or add a2
//  to a3
//  and subtract a2
//  from a1
// ;
// during the second operation, you either add a3
//  to a2
//  and subtract a3
//  from a4
// , or add a3
//  to a4
//  and subtract a3
//  from a2
// ;
// ...
// during the last operation, you either add an−1
//  to an−2
//  and subtract an−1
//  from an
// , or add an−1
//  to an
//  and subtract an−1
//  from an−2
// .
// So, during the i
// -th operation, you add the value of ai+1
//  to one of its neighbors, and subtract it from the other neighbor.

// For example, if you have the array [1,2,3,4,5]
// , one of the possible sequences of operations is:

// subtract 2
//  from a3
//  and add it to a1
// , so the array becomes [3,2,1,4,5]
// ;
// subtract 1
//  from a2
//  and add it to a4
// , so the array becomes [3,1,1,5,5]
// ;
// subtract 5
//  from a3
//  and add it to a5
// , so the array becomes [3,1,−4,5,10]
// .
// So, the resulting array is [3,1,−4,5,10]
// .

// An array is reachable if it can be obtained by performing the aforementioned sequence of operations on a
// . You have to calculate the number of reachable arrays, and print it modulo 998244353
// .

// Input
// The first line contains one integer n
//  (3≤n≤300
// ).

// The second line contains n
//  integers a1,a2,…,an
//  (0≤ai≤300
// ).

// Output
// Print one integer — the number of reachable arrays. Since the answer can be very large, print its remainder modulo 998244353
// .

// Examples
// inputCopy
// 4
// 1 1 1 1
// outputCopy
// 3
// inputCopy
// 5
// 1 2 3 5 0
// outputCopy
// 7

#include <bits/stdc++.h>
using namespace std ;

// #define ll long long
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
ll dp[300][180000]; // [indx][value]
int solve(vii & a ,int indx){
    if(indx==n-1){

    }
    else {
        if(a[indx]==0){
            if(dp[indx+1][a[indx+1]]==0){
                int h = solve(a,indx+1) ;
                
                return h ; 
            }
            return  ;
        }
        else {
            a[indx+1]+= a[indx] ;
            int h = solve(a,indx+1) ;
            a[indx+1]-= 2*a[indx] ;
            int k = solve(a, indx+1) ;
            a[indx+1]+= a[indx] ;
            return h+k ;
        }
    }
}

int main(){
    int n ;
    cin>>n ;
    vii a(n) ;
    for(int e=0 ; e<n ;e++){
        cin>>a[e] ;
    }
    //input is done 
    for(int e=0 ;e<300 ;e++){
        for(int p=0 ;p<180000; p++){
            dp[e][p]=0 ;
        }
    }
    dp[1][a[1]]=1 ;
    cout<<solve(a,1)<<endl ;
    
    
}