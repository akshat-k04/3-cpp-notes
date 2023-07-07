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
        cout<<a[e]<<setw(1) ;
    }
    cout<<endl ;
}

//solution here 


int main(){
    int t;
    cin>>t ;
    for(int r=0 ;r<t ;r++){
        int n ; //5
        cin>>n ;
        int k ; //2
        cin>>k ;
        vii a(n) ; //4 5 6 8 11
        for(int e=0 ;e<n ;e++){
            cin>>a[e] ;
        }
        sort(all(a)) ;
        //input is done
        int ans=a[n-1]-a[0] ; //5 

        for(int e=1 ;e<=min(k,a[0]) ;e++){

            int mini = int(a[0]/e) ; //2
            int maxi=mini ;//2
            for(int f=0 ;f<n ;f++){
                int p ; 
                p =a[f]/maxi  ;
                p=min(p,k) ; //1
                
                if(a[f]/(maxi*1.0)!=p){
                    
                    if(int(a[f]/p)!=maxi){
            // cout<<f;

                        p=a[f]/mini ;
                        p=min(p,k) ;
                        if(int(a[f]/p)>mini &&int(a[f]/p)<=maxi){
                            // all set
                        }
                        else{
                            int q = a[f]/(maxi) ;
                            q++ ;
                            q=min(q,k);
                            if(abs(mini-int(a[f]/q))>=int(a[f]/p)-maxi){
                                maxi=max(maxi,int(a[f]/p)) ;
                                mini=min(mini,int(a[f]/p)) ;

                            }
                            else{
                                mini=min(mini,int(a[f]/q)) ;
                                maxi=max(maxi,int(a[f]/q)) ;

                            }
                        }

                    }
                }
                // cout<<e<<" "<<f<<endl ;

            }
            // cout<<maxi<<" "<<mini<<endl ;
            ans=min(ans, (maxi-mini)) ;
        }
        // ans = min(ans,a[n-1]/k) ;
        // cout<<r<<endl; 
        cout<<ans<<endl ;
    }
}