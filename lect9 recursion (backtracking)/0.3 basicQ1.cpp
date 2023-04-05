//palindrom check

#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define pob pop_back


typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vii;



//solution here 

bool generate(vii& a,int n , int i){
    if(i>n-1-i){
        return true  ;
    }
    else if(a[i]!=a[n-1-i]){
        return false  ;
    }
    else{
        return generate(a,n,i+1) ;
    }
}



int main(){
    int n ;
    cin>>n ;
    vii a ;
    for(int e=0 ;e<n ;e++){
        int h ;
        cin>>h ;
        a.pb(h) ;
    }
    // input is done

    cout<<generate(a,n,0); 
}