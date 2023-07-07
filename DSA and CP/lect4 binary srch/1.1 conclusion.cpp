/*
1. upper_bound :- return the index of integer that is smallest greater number then the given value
   lower_bound :- it will return the index of integer that is equal to the given value or if it is not present the return the larger then that value

2. a.begin() points on 0th index
   a.end()  points after n-1th 
   a.rbegin() points on n-1 th index
   a.rend()  point before 0th index
   rbegin(),ren() we use when array is decreasing

        6    5   4   3   2   1        want to find the upper bound of 3 i.e. ans is 4
  |     |                    |     |
rend  begin               rbegin  end
    to find the upper bound of 3 
    as it is decreasing so
    int rindex = upper_bound(a.rbegin() ,a.rend(),3) - rbegin() ;
    int actualinde = n-1-rindex ;

3. iterator for num 2 can be a.begin()+4 or a.rbegin()+1
   
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


int main(){
    vii a ;
    for(int e= 0 ; e<10 ; e++){
        a.pb(10-2*e) ;
    }
    //input is done

    int rindex = upper_bound(a.rbegin() , a.rend(),7) - a.rbegin() ;
    cout<<*(a.begin()) <<endl;
    cout<<*(a.end()) <<endl;
    cout<<*(a.rbegin()) <<endl;
    cout<<(a.rend()) -a.rbegin()<<endl;


}