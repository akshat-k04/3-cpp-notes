// reference operator i.e. & has 2 use 
 #include <bits/stdc++.h>
using namespace std ;
int main(){
    int a =56 ;

    //#1st use 
    //cout<< &a ; // here & is used for address of a
    // we get address of a 
    

    //#2nd use 
    int& b = a ;
    // it means that in memory there is a location whose name is give as a
    // this line tell that that location can also be called as b
    // my name is ram and akshat 
    // if someone ask the address of myself then in return he get agra 
    // wheather that person recognise me as ram or akshat
    //this same concept is used in 9th line

    int* s ;
// data type int* store the address of integer
    s= &a ;
    cout<< s<<endl ;
    //cout<<s; give the address of a a a out put because s store the address of a

    cout<< &s <<endl ;
    // this give output of its own address 
    
    cout<<*s <<endl;
    //this give output of value that is stored in address which is stored in s


/**********note***********
 1. & has 2 work
 int& :- used to make 1 more name of value as shown above
 &a:- this will tell the address of a 

 2. * has 2 work
 int* a=&s:-  this means a will store the address of s. a is called pointer
 *a:- means if a is pointer variable (means it store the address of any other value) then this operation will give the 
      value which is stored at address which is stored in a 
      */



}