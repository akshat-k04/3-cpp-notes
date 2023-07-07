// finding prime facors 
// complexity is O(sqrt(n)) ;

#include <bits/stdc++.h>
using namespace std ;

#define pb push_back

typedef vector<int> vii;
typedef vector<pair<int,int>> vpii;


//solution here 

void print(vpii & primefactors){
    for(int e= 0;e<primefactors.size() ; e++){
         cout<<primefactors[e].first<<" "<<primefactors[e].second <<endl ;
    }
}

void primefact(int n,vpii & primefactors){
    for(int e=2 ;e<=sqrt(n);e++){
        if(n%e==0){
            primefactors.pb({e,0});
            while(n%e==0){
                n/=e ;
                primefactors[primefactors.size()-1].second++ ;
            }
        }
    }
    if(n!=1){
        primefactors.pb({n,1}) ;
    }
}



int main(){
    int n ;
    cin>>n ;
    vpii primefactors ;
    primefact(n,primefactors) ;
    print(primefactors) ;
}