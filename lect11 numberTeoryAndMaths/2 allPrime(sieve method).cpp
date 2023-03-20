//done

 #include <bits/stdc++.h>
using namespace std ;
vector<int> prime(100000,1) ;
//1 means prime

void sieve(int a){
    for(int e=2 ; e<=a ;e++){
        if(prime[e]==1 &&e*e<=a){
            for(int p=e*e ;p<=a ;p+=e){
                 prime[p]=0 ;
            }
        }
    }
    for(int e=2  ; e<=a ;e++){
        if(prime[e]==1){
            cout<<e<<" ";
        }
    }
}
int main(){
    int a ;
    cin>> a ;
    prime[0]=0 ;
    prime[1]=0 ;
    sieve(a) ;
}


// key idea 

// key idea here is you can see on google by searching sieve method for prime factorization 