// print all sub sequence whose sum is k
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

//solution here 

vector<vii> ans ;
int k ;

//solution 1 
//approch:- just feel that approch
// void generate(vii &a,int i ,vii & temp){
//     int n = a.size() ;
//     for(int e=i ;e<n ;e++){
//         temp.pb(a[e]) ;
//         ans.pb(temp) ;
//         generate(a,e+1 ,temp) ;
//         temp.pop_back() ;
//     }
// }



//solution 2
//approch :- here we use approch that if we have 1 2 3 4 so eighter we take or we not take it to make a sub sequence and in one case 1 take it and in other case i dont take it 
void generate2(vii&a , int i,vii & temp,int & sum){
    int n = a.size() ;
    if(i==n){
        if(sum==k){
            
            ans.pb(temp) ;
        }
        return ;
    }
    temp.pb(a[i]) ;
    sum+=a[i] ;
    generate2(a,i+1, temp,sum) ;
    temp.pop_back() ;
    sum-=a[i] ;
    generate2(a,i+1,temp,sum) ;
}

int main(){
    int n ;
    cin>> n; 
    cin>>k ;
    vii a ;
    for(int e=0 ;e<n ;e++){
        int h ;
        cin>>h ;
        a.pb(h) ;
    }
    // input is done
    vii temp ;
    //solution1// generate(a,0,temp) ;
    int sum=0 ;
    generate2(a,0,temp,sum) ;

    for(int e=0 ;e<ans.size() ; e++){
        for(int f=0 ; f<ans[e].size() ; f++){
            cout<<ans[e][f]<<" " ;
        }
        cout<<endl ;
    }
}