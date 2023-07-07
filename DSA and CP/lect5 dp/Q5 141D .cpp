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

void generate(vii &a){
    vii store(180005,0) ;
    vii latest(180005 ,0) ;
    int n = a.size() ;
    store[a[1]]=1  ;
    
    for(int e=1 ;e<n-1 ;e++){
        for(int num=-90001 ; num<=90001 ; num++){
            int f ;
            if(num<0){
                f = 180005+num ;
            }
            else{
                f = num ;
            }
            if(store[f]!=0){
                // cout<<e<<endl ;
                int temp ;
                if(a[e+1]+num<0){
                    temp = 180005 + a[e+1]+num ;
                }
                else{
                    temp = a[e+1]+num ;
                }
                // cout<<e<<" "<<f<<endl ;
                latest[temp]+=store[f] ;
                latest[temp]%=primeInt ;
                if(f!=0){
                    if(a[e+1]-num<0){
                        temp = 180005 +a[e+1]-num ;
                    }
                    else{
                        temp =a[e+1]-num ;
                    }
                // cout<<e<<" "<<f<<endl ;

                    latest[temp]+=store[f] ;
                    latest[temp]%=primeInt ;
                } 
                store[f]=0 ;
            }
            
        }
        for(int e=0 ;e<180005 ;e++){
            store[e]=latest[e] ;
            latest[e]=0 ;
        }
        
        
    }
    // for(int e=0; e<180005 ; e++){
    //     if(store[e]!=0){
    //         cout<<store[e]<<endl ;
    //     }
    // }
    ll sum =0 ;
    for(int e=0; e<180005 ; e++){
        sum+= store[e] ;
        sum%=primeInt ;
        if(store[e]!=0){
            // cout<<e<<endl ;
        }
    }
    // cout<<store[180005-10]<<endl;
    cout<<sum<<endl ;
}

int main(){
    
    int n ;
    cin>>n ;
    vii a(n) ;

    for(int e=0 ;e<n ;e++){
        int h ;
        cin>>h ;
        a[e]=h ;
        // cout<<'h';
    }
    generate(a) ;
    return 0 ;
}
