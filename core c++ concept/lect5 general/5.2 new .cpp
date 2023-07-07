 #include <bits/stdc++.h>
using namespace std ;
int main(){
    int * f =  new int(5) ;
    // basically the above line make a pointer which store the address 
    // where 5 is present in memory 
    // 
    cout<< f ;
    cout<< endl << &f ;

    // we can also do this 
    int *h ;
    h= new int  ;
    *h = 5 ;
    // we can write 4th line in this 3 lines 
}