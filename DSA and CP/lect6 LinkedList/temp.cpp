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

    int t ;
    cin>>t ;
    //for loop for test cases
    for(int r=0 ;r<t ;r++){
        int n ;
        cin>>n ;
        // taking input 
        map<int,int> mp ;
        for(int e=0 ;e<n ;e++){
            int l,r,a,b ;cin>>l>>r>>a>>b ;
            // we have to take 4 numbers as input but useful are only 2
            mp[l]=max(b,mp[l]);
        }

        
        //making a vector of pair from map 
        vpii list ;
        int limit =-1 ;
        for(auto v:mp){
            int bval= v.sec;
            if(bval<=limit)continue ;
            limit= bval ;
            list.pb({v.fir,bval}) ;
        }


        // making a dp array
        n = list.size() ;
        vii dp(n) ;
        int iniindx =0 , finalindx =1 ,value =0 ;
        for(int e=0 ;e<n-1 ;e++){
            value= list[e].sec ;
            if(list[e+1].fir<= value && list[e+1].sec>= value){
            }
            else{
                for(int f=iniindx ; f<finalindx;f++){
                    dp[f]=value ;
                }
                iniindx=finalindx; 
            }
            finalindx++ ;
        }
        value = list[n-1].sec  ;
        for(int f= iniindx ; f<finalindx;f++){
            dp[f] = value ;
        }


        // making a array which has element same as first element of list 
        vii temper ;
        for(int e=0 ;e<n ;e++){
            temper.pb(list[e].fir) ;
        }

        // we have q query and answering those q query
        int q ; cin>>q ;
        vii ans ;
        for(int e=0 ;e<q ;e++){
            int x ;cin>>x ;
            int indx = upper_bound(temper.begin() , temper.end() , x)-temper.begin() ; indx-- ;
            if(indx==-1)ans.pb(x) ;
            else ans.pb(max(x,dp[indx])) ;
        }
        print(ans) ;
    }
}