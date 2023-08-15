// https://www.codingninjas.com/studio/problems/partition-equal-subset-sum_892980
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
    int n ;
    cin>>n ;
    vii a(n) ;
    for(int e=0 ;e<n ;e++)cin>>a[e] ;

    if(n%2==1)return 0 ;
    else{
        // use file 15 code with k= n/2 ;
    }
}