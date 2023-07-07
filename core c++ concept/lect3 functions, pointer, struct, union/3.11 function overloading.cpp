 #include <bits/stdc++.h>
using namespace std ;
int add(int a, int b   ){
    return a+b ;
}
int add(int a, int b , int c  ){
    return a+b+c ;
}
int main(){
    int a =9 ;
    int b =8 ;
    int c=5 ;
    cout<< add(a,b)<< endl ;//this line call function which is in 3rd line
    cout<< add(a,b,c)<< endl ;//this line call function which is in 6th line
}

// bascically when we call function then compiler 1st match the prototype we write with various functions we make 
// then compiler see what is the name of function we call 


// this is called overoading means when we use same name of function

