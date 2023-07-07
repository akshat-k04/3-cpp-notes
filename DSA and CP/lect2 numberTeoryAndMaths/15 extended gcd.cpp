/*
here we find the integer solution of eq ax+by = gcd(a,b) 
eg:- 57,81
step:
     1.find the gcd 
       it is 3
     2. eq is
       57x+81y=3
       for rest of the step
       
       for proof see this 
       https://cp-algorithms.com/algebra/extended-euclid-algorithm.html
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
typedef vector<vector<int>> vvii;

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
    int x,y ;
    int a,b ;
    cin>>a>>b ;
    cout<<extendedGcd(a,b,x,y) ; // this will print gcd
}