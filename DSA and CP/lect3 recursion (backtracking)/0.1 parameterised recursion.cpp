// find the sum of 1st n numbers 

#include <bits/stdc++.h>
using namespace std ;


void generate(int n , int &sum){
    if(n==0){
        return ;
    }
    else {
        sum+= n;
        generate(n-1 , sum) ;
    }
}

// in this way basically we use parameter and update it
int main(){
    int n ;
    cin>>n ;
    int sum =0 ;
    // this is our parameter 

    generate(n,sum) ;
    cout<<sum<<endl ;
}