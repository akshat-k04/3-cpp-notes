// quick sort
// worst case time complexity is O(n^2) ; // when pivot selected is largest or smallest every time
//  avg case time complexity is O(nlog (n)) ;
//approch:- here i take a number put it on its correct place ,then element which are less than or equal to pivot put on right  then make 2 sub array one is before pivot and other is after pivot and do same thing

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

const ll largestLL= 1e18;
const int largestI = 1e9;
const ll primeInt2 = 1000000007;
const int primeInt = 998244353;



//solution here 

int indxfinder(vii &a ,int start,int end){
    int counter =0 ;
    for(int e=start+1 ; e<=end; e++){
        if(a[start]>=a[e]){
            counter++ ;
        }
    }
    // cout<< (start+counter)<<"K";
    return (start+counter) ;
}

void sortall(vii & a , int start, int end){
    int j = end+2 ;

    for(int e=start ; e<=end; e++){
        if(a[e]>a[end+1]){
            while(a[j]>a[end]){
                j++ ;
            }
            swap(a[e],a[j]) ;
        }
    }
}

void quickSort(vii &a , int start ,int end){
    int index = indxfinder(a,start,end) ;
    swap(a[index],a[start]) ;
    sortall(a,start,index-1);
    if(end-start>1){
        quickSort(a,start,index-1) ;
        quickSort(a,index+1 , end) ;
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
    //input is done
    quickSort(a,0,n-1) ;

    for(int e=0 ;e<n ;e++){
        cout<<a[e]<<" " ;
    }
}