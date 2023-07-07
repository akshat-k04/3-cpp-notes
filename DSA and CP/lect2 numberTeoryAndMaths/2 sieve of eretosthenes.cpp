// tells all the number that are prime till 100000
// the time complexity is O(n*log(log(n))) 

#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define pob pop_back

typedef vector<int> vii;

//solution here 

void createSieve(vii &a){
    // 0 means composite
    // 1 means prime 
    // 1 is not a prime nor composite but here we consider it as composite
    a[0]=0 ;
    a[1]=0 ;
    for(int e=2 ;e<=sqrt(a.size())+1 ;e++){
        if(a[e]==1){
            int f=e*e ;
            while(f<a.size()){
                a[f]=0 ;
                f+=e ;
            }
        }
    }
}

int main(){
    vii sieve(100006,1) ;
    createSieve(sieve); 
}