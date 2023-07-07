/*

1. using extended gcd we get integral valus of x,y such that 
   a*x+b*y = gcd(a,b) 

2. now , let a,b are co prime and i have to find the modular inverse of a wrt b
   so, gcd(a,b) =1 
   and eq become 
   a*x+b*y =1
   now take mod b both side

3. a*x % b +0 = 1%b
   => a*x = 1 (mod b) 
   so , we can say that 
   c is the modular inverse of a 
   where c  = (x%b +x)%b 
   we do this because if x is negative so to make it positive
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


//solution here 
int extendedGcd(int a, int b, int& x, int& y) { //return value is gcd
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main(){
    int a,b,x,y ;
    cin>>a>>b ;
    int gcd = extendedGcd(a,b,x,y) ;
    if(gcd!=1){ // means a,b, are not co prime
        cout<<"NO SOLUTION"<<endl ;
    }
    else{
        int inv = (gcd%b +b) %b ;
        cout<<"MODULAR INVERSE OF A WRT B IS "<<inv <<endl ;
    }
}