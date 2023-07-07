/*
the concept here we use is very useful to ifnd the ans where we cant make 2d array due to time constraint
https://codeforces.com/contest/1795/problem/C
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

//solution here 


int main(){
    int t;
    cin>>t ;
    for(int r=0 ;r<t ;r++){
        int n ; //1
        cin>>n ;
        vll a(n),b(n) ;
        for(int e=0 ;e<n ;e++){
            cin>>a[e] ;
        }
        for(int e=0 ;e<n ;e++){
            cin>>b[e] ;
        }
        //input is done
        // b= taster limit one time
        vll tastertillk ; //
        tastertillk.pb(b[0]) ;
        for(int e=1 ;e<n;e++){
            tastertillk.pb(tastertillk[e-1]+b[e]) ;
        }
        //we got the k
        vll ans(n+1) ;
        vll factor(n+1) ;
        for(int e=0 ;e<n ;e++){
            ll number ;
            if(e==0){
                number = a[e] ;
            }
            else{
                number = a[e] +tastertillk[e-1] ;
            }
            int index = upper_bound(tastertillk.begin()+e , tastertillk.end(),number)-tastertillk.begin() ;
            if(index>e){
                ans[e]++ ;
                ans[index]-- ;
            }
            if(index==0){
                factor[index]+=(number) ;
            }
            else{
                factor[index]+=(number-tastertillk[index-1]) ;
            }
        }
        vll realans(n) ;
        ll temper=0 ;
        for(int e=0 ;e<n ;e++){
            temper+=ans[e] ;
            realans[e] = temper*b[e] ;
            realans[e]+= factor[e] ;
            // cout<<ans[e]<<" " ;
            cout<<realans[e]<<" ";
        }
        cout<<endl ;
    }
}