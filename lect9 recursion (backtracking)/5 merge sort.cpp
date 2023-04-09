// merge sort 
//approch :- here we first divide then merge in sorted order

// key point :- if we have 2 sorted array and we want to merge and make it sorted it can be done in o(m+n)
                //use 1 pointer on 1st and other on 2nd compare elements and put it in the temp array
                

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

void generate(vii & a,int ini,int end){
    if(end-ini>1){
        generate(a,ini,(ini+end)/2) ;
        generate(a,(ini+end)/2 +1,end) ;
        int ptr1 = ini ;
        int ptr2= (ini+end)/2 +1 ;
        vii temp ;
        while(ptr1<=(ini+end)/2 || ptr2 <= end){
            if(ptr1>(ini+end)/2){
                temp.pb(a[ptr2]) ;
                ptr2++ ;
            }
            else if(ptr2 > end){
                temp.pb(a[ptr1]) ;
                ptr1++ ;
            }
            else{
                if(a[ptr1]>a[ptr2]){
                    temp.pb(a[ptr2]) ;
                    ptr2++ ;
                }
                else{
                    temp.pb(a[ptr1]) ;
                    ptr1++ ;
                }
            }
        }
        for(int e= ini ; e<= end ; e++){
            a[e] = temp[e-ini] ;
        }
    }
    else{
        if(a[ini]>a[end]){
            int temp = a[end] ;
            a[end]= a[ini] ;
            a[ini]= temp ;
        }
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
    
    generate(a,0,n-1) ;
    for(int e=0 ;e<n ;e++){
        cout<<a[e]<<" " ;
    }
}