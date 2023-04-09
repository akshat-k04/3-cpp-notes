//leet code link :- https://leetcode.com/problems/combination-sum-ii/
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


//better solution

void generate(vii & storer , vector<vii> &ans ,vii & temp , int sum , int num,int summer ){

    if(num==54){
        if(sum==summer){
            ans.pb(temp) ;
        }
        return ;
    }
    generate(storer ,ans , temp,sum , num+1,summer) ;
    int troma = sum ;
    for(int e=0; e<storer[num] && sum<=summer ; e++){
        sum+=num ;
        temp.pb(num) ;
        generate(storer,ans,temp,sum,num+1,summer);
    }
    while(sum!=troma){
        sum-=num ;
        temp.pob() ;
    }
}

int main(){
    int n ;
    cin>>n ;
    int summer ;
    cin>>summer ;
    vii a ;
    vii storer(55,0) ;
    for(int e=0 ;e<n ;e++){
        int h ;
        cin>>h ;
        a.pb(h) ;
    }
    for(int e=0 ;e<n ;e++){
        storer[a[e]]++ ;
    }
    //input is done

    vector<vii> ans ;
    vii temp ;
    generate(storer,ans ,temp,0,0,summer);
    for(int e=0 ;e<ans.size(); e++){
        for(int f=0 ;f<ans[e].size() ; f++){
            cout<<ans[e][f]<<" " ;
        }
        cout<<endl ;
    }
}











































// void generate(vii &a, vector<vii> &ans ,int summer , vii& temp,int num,int sum){
//     if(num==a.size()){
//         if(sum==summer){
//             ans.pb(temp) ;
//         }
//         return ;
//     }
//     else{
//         num++ ;
//         generate(a,ans ,summer,temp ,num ,sum) ;
//         num-- ;
//         temp.pb(a[num]) ;
//         sum+= a[num] ;
//         num++ ;
//         generate(a,ans ,summer,temp,num,sum) ;
//         num-- ;
//         sum-= a[num] ;
//         temp.pob() ;
//     }
// }

// int main(){
//     int n ;
//     cin>>n ;
//     int summer ;
//     cin>>summer ;
//     vii a ;
//     for(int e=0 ;e<n ;e++){
//         int h ;
//         cin>>h ;
//         a.pb(h);
//     }
//     //input is done
//     vii temp ;
//     vector<vii> ans ;
//     generate(a,ans ,summer ,temp , 0,0) ;
//     for(int e=0 ;e<ans.size() ; e++){
//         sort(all(ans[e])) ;
//     }
//     sort(all(ans)) ;
//     vector<vii> realans ;
//     for(int e=0 ;e<ans.size() ; e++){
//         if(realans.size()==0){
//             realans.pb(ans[e]) ;
//         }
//         else{
//             if(realans[realans.size()-1]!=ans[e]){
//                 realans.pb(ans[e]) ;
//             }
//         }
//     }
// }

