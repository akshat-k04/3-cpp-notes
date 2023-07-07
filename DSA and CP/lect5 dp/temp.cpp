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

void print(vii & a){
    for(int e=0 ;e<a.size() ;e++){
        cout<<a[e]<<" ";
    }
    cout<<endl ;
}

//solution here 

void merger(vector<int> &a , int ini ,int end){
    vector<int> temp ;
    int ini1=ini ;
    int mid = (ini+end)/2 ;
    int ini2 =mid+1;
    while(ini1<=mid && ini2<=end){
        if(a[ini1]>a[ini2]){
            temp.push_back(a[ini2]) ;
            ini2++ ;
        }
        else{
            temp.push_back(a[ini1]) ;
            ini1++ ;
        }
        // cout<<temp.size()<<endl;
    }
    if(ini1>mid){
        while(ini2<=end){
            temp.push_back(a[ini2]) ;
            ini2++ ;
        }
    }
    if(ini2>end){
        while(ini1<=end){
            temp.push_back(a[ini1]) ;
            ini1++ ;
        }
    }
    for(int e=ini ; e<=end ;e++){
        a[e] = temp[e-ini] ;
    }
    return ;
}

void sorting(vector<int> &a , int ini ,int end){
    if(end-ini<=1){
        if(a[ini]>a[end]){
            swap(a[end],a[ini]) ;
        }
        return ;
    }
    int mid = ini+end ;
    mid/=2 ;
    sorting(a,ini,mid) ;
    sorting(a,mid+1 ,end) ;
    merger(a,ini,end) ;
}

int main(){
    int n ;
    cin>>n ;
    vii a ;
    for(int e=0 ;e<n ;e++){
        int h; 
        cin>>h ;
        a.pb(h) ;
    }
    sorting(a,0,n-1) ;
    print(a) ;
}