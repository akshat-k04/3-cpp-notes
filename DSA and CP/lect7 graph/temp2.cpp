#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define pob pop_back
#define fir first 
#define sec second
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vii;
typedef vector<vector<int>> vvii;

void print(vii& a){int n = a.size() ;for(int e=0 ;e<n ;e++)cout<<a[e] <<' ';cout<<endl ;}

int main(){
    string temp ="" ;
    string ans ="" ;
    for(int e=0 ;e<112;e++){
        if(e%7==0){
            cout<<ans<<endl ;
            ans="" ;
        }
        cin>>temp ;
        ans+=temp ;
        ans+=" & " ;
    }
    cout<<ans<<endl ;
    // cout<<ans;
}

/*





 
 


 

 






 
 





 




*/