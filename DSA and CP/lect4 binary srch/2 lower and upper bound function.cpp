//let we have array now the lower bound and upper bound is defined only for element weather it is present in array or not

//upper_bound(,,):- smallest value that is greater then the given value 
//lower_bound(,,) :- greaterthan or equal to the given value 
// code is silmilar to tht of previous one


//it the vector is in decreasing order then we have to do this
// upper_bound(a.rbegin() , a.rend() , 5) ;
// instead of begin,end we use rbegin,rend
// rbegin represent the ite after last element while rend represent the ite of 1st element 
// rbegin() +1 means it will represent the last element 



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


int main(){
    vii a ;
    a.pb(10) ;
    a.pb(20) ;
    a.pb(30) ;
    a.pb(40) ;

    auto it = lower_bound(a.begin() , a.end() , 30) ;
    cout<<it-a.begin() ;
}