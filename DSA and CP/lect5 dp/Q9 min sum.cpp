/*
We are given an “N*M” matrix of integers. We need to find a path from the top-left corner to the bottom-right corner of the matrix, such that there is a minimum cost past that we select.

At every cell, we can move in only two directions: right and bottom. The cost of a path is given as the sum of values of cells of the given matrix.
*/

// link:- https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349

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

int generate(vvii &a){
    int n = a.size() ;
    int m = a[0].size() ;
    vvii ans(n) ;
    for(int e=0 ;e<n ;e++){
        for(int f=0 ;f<m ;f++){
            if(e==0){
                if(f==0){
                    ans[e].pb(a[e][f]) ;
                }
                else{
                    ans[e].pb(ans[e][f-1]+a[e][f]) ;
                }
            }
            else{
                if(f==0){
                    ans[e].pb(ans[e-1][f]+a[e][f]) ;
                }
                else{
                    ans[e].pb(min(ans[e-1][f],ans[e][f-1])+a[e][f]) ;
                }
            }
        }
    }
    return ans[n-1][m-1] ;
}

int main(){
    int t ;
    cin>>t ;
    for(int r=0 ;r<t ;r++){
        int n,m ;
        cin>>n>>m ;
        vvii a ;
        for(int e=0 ;e<n ;e++){
            vii temp ;
            for(int f=0 ;f<m ;f++){
                temp.pb(a[e][f]) ;
            }
            a.pb(temp) ;
        }
        //input is done
        generate(a) ;
    }
}