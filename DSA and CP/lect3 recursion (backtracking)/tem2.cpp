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
    int t ;
    cin>>t ;
    for(int r=0 ;r<t ;r++){
        string i,s ;
        cin>>i>>s ;
        int n = i.size() ;
        int g = s.size() ;
        int countnum=0 ;
        int possible=false ;
        int ite =0 ;
        while(ite<g && !possible){
            if(s[ite]==i[0]){
                int temper =ite ;
                int tempcount =0 ;
                for(int e=0 ;e<n && temper<g ; e++){
                    if(i[e]!=s[temper]){
                        while(i[e]!=s[temper]&& temper<g){
                            temper++ ;
                            tempcount++ ;
                        }
                    }
                    if(e==n-1 && i[e]==s[temper]){
                        possible= true ;
                        tempcount+= g-1-tempcount ;
                        countnum+= tempcount ;
                    }
                }
            }
            else{
                ite++ ;
                countnum++ ;
            }
        }
        if(possible){
            cout<<countnum<<endl ;
        }
        else{
            cout<<"IMPOSSIBLE"<<endl ;
        }
    }
}