 #include <bits/stdc++.h>
using namespace std ;
int main(){
    int a =10 ;
    int & y = a ;
    // when we write &y it means we write we use address of y
    // now &y =a means at the address of y same thing done which are done with a
    cout<< y ; // we get 10
    a=15 ;
    cout<< y ; // we get 15
    return 0 ;
}