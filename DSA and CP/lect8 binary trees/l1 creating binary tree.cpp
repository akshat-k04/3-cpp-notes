// for creating a tree we caneighter use a class or a structure

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

class noding {
    public:
       int dat ;
       noding*lft ;
       noding * rght ;

       noding(int val){ // constructor
           dat=val ;
           lft=NULL ;
           rght=NULL ;
       }
} ;

int main(){
    
    noding *fk = new noding(10) ;
    cout<<fk->dat<<endl ;
}