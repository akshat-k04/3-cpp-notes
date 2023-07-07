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

ll generate(vll & a){
    vll ans ;
    int n = a.size() ;
    if(n==1){
        return a[0] ;
    }
    ans.pb(a[0]) ;
    for(int e=1 ;e<n-1 ;e++){
        if(e==1){
            ans.pb(a[1]) ;
        }
        else if(e==2){
            ans.pb(a[0]+a[2]) ;
        }
        else{
            ans.pb(max(ans[e-2],ans[e-3])+a[e]) ;
        }
    }
    if(n==2){
        return ans[n-2] ;
    }
    else{
        return max(ans[n-2],ans[n-3]) ;
    }
}

int main(){
    int t ;
    cin>>t ;
    for(int r=0 ;r<t ;r++){
        int n ;
        cin>>n ;
        vll a ;
        for(int e=0 ;e<n ;e++){
            ll h ;
            cin>>h ;
            a.pb(h) ;
        }
        //input is done

        ll temp1 = generate(a) ;
        reverse(all(a)) ;
        ll tem2 = generate(a);
        cout<< max(tem2,temp1)<<endl ;
    }
}