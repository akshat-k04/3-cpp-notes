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
gcd :- __gcd(a,b)
to convert int to string to_string(number)
to convert char to int we have to handle it mannually int a = '6' - '0' 
queue<int>, stack<int> --> has push() ,pop() , front() for queue ,top() for stack , 
reverse(a.begin() , a.end())
st.erase(st.begin()+index) or st.erase(st.begin()+iniIndex , st.begin() + lstIndex)// note that lst index will not erase it is similar to open bracket 
 upper_bound(a.begin(),a.end(),5):- gives iterator strictly less than the 5
lower_bound(a.begin(),a.end(),5):- greater than or equals to the 5
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
    int n,m ;
    cin>>n ;
    cin>>m ;
    vii a,b ;
    for(int e=0 ;e<n ; e++){
        int h;
        cin>>h ;
        a.pb(h) ;
    }

    for(int e=0 ;e<m ; e++){
        int h ;
        cin>>h ;
        b.pb(h) ;
    }
    //input is done
    int maxsum =a[0] ;
    int sum = a[0] ;
    for(int e=1 ;e<n ; e++){
        maxsum= max(sum,maxsum) ;
        if(sum<0){  
            sum =0 ;
        }
        if(a[e]<0){
            if(sum+a[e]>=0){
                sum+= a[e] ;
            }
            else{
                sum = a[e] ;
            }
        }
        else{
            sum+=a[e] ;
        }
    }
    maxsum= max(sum , maxsum) ;
    cout<<maxsum<<endl ;
    //got max sum of sub array 

    vii inisum;
    int temp=0 ;
    for(int e=0 ;e<n ; e++){
        temp+= a[e] ;
        inisum.pb(temp);
    }
    sort(all(inisum)) ;
    int inimax = inisum[n-1] ;

    //got index upto which i get max sum 
    temp=0 ;
    for(int e=n-1 ;e>=0 ; e--){
        temp+= a[e] ;
        inisum[e] = temp ;
    }
    sort(all(inisum)) ;
    int lstmax = inisum[n-1] ;
    

    // i got the lst ini index 
    cout<<inimax<<" "<<lstmax<<endl ;
    vii ans ;
    int bordermax = max(inimax,lstmax) ;
    for(int e=0 ;e<m ; e++){
        if(b[e]<0){
            
            ans.pb(max(b[e] ,maxsum)) ;
        }
        else{
            bordermax+= b[e] ;
            ans.pb(max(bordermax,maxsum)) ;
        }
    }

    sort(all(ans)) ;
    cout<<ans[m-1] <<endl ;
}