// https://www.youtube.com/watch?v=46zD5d9y9b4&t=1016s

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

/*
approach:- 
we have n numbers now in first kill you kill kth person so, now you have k-1 person 
lets make it as a n-1 ,k . for that 
we are making k+1=1 , k+2=2 , k+3=3 ... , r=(k+r)%n-1 
if we have n-1,k problem which starts as a normal problem and we have its answer
then just add k to that and take modulo n we get the ans 
*/

int ans(int n, int k){
    if(n==1)return 0 ;
    return (ans(n-1,k)+k)%n ;
}


int main(){
    int n ,k ;
    cin>>n>>k ;
    cout<<ans(n,k)+1 ;
}