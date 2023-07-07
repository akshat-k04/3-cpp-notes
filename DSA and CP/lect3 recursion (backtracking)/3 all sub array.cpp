//not solved by recursion
// print all the sub array
//if want to solve can easily solve by 2 pointer

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
void generate(vii & a , int i , vii & temp){
    if(i==a.size()){
        return ;
    }
    temp.pb(a[i]) ;
    ans.pb(temp) ;
    generate(a,i+1,temp) ;
    
}

int main(){
    int n ;
    cin>>n ;
    vii a ;
    for(int e=0 ;e<n ;e++){
        a.pb(e) ;
    }
    // input is done
    vii temp ;
    generate(a,0,temp) ;

    for(int e=0 ;e<ans.size() ; e++){
        for(int f=0 ; f<ans[e].size() ; f++){
            cout<<ans[e][f]<<" " ;
        }
        cout<<endl ;
    }
}