// print all sub sequence
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
void generate2(vii&a , int i,vii & temp){
    int n = a.size() ;
    if(i==n){
        ans.pb(temp) ;
        return ;
    }
    temp.pb(a[i]) ;
    generate2(a,i+1, temp) ;
    temp.pop_back() ;
    generate2(a,i+1,temp) ;
}

int main(){
    int n ;
    cin>> n; 
    vii a ;
    for(int e=0 ;e<n ;e++){
        a.pb(e+1) ;
    }
    // input is done
    vii temp ;
    //solution1// generate(a,0,temp) ;

    generate2(a,0,temp) ;

    for(int e=0 ;e<ans.size() ; e++){
        for(int f=0 ; f<ans[e].size() ; f++){
            cout<<ans[e][f]<<" " ;
        }
        cout<<endl ;
    }
}