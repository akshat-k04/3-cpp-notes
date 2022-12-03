 #include <bits/stdc++.h>
using namespace std ;
int max(int a,int b,int c,int d){
    int ma,mb ;
    ma =0 ;
    mb =0 ;
    if(a>b){
        ma = a ;
    }
    else {
        ma=b ;
    }
    if(c>d){
        mb=c ;
    }
    else {
        mb =d ;
    }
    int n = (mb>ma)? mb:ma ;
    return n ;
}
struct StudentData{
    int age ;
    string nick_name ;
    int salary ;
} ;
int main(){
    // structure is a user defined data type
    //here we can store diff diff items
    // array is used to store same type of items eg:- all int or char or float  etc


    struct StudentData akshat,aastha,garvit,ravi,shanu ; // define object 
     akshat.age=18;
     akshat.nick_name ="ram" ;
     akshat.salary= 45000 ;
     aastha.age = 15 ;
     aastha.nick_name ="kittu" ;
     aastha.salary=35000 ;
     garvit.age=18 ;
     garvit.nick_name="kishan";
     garvit.salary=38000 ;
     cin>> ravi.salary ;
     cin>> ravi.age ;
     cin>>ravi.nick_name ; //write  jay bhaiya
     shanu.age = 24 ;
     cin>>shanu.nick_name ;
     shanu.salary= 40000 ;

     cout<< max(akshat.salary,garvit.salary,aastha.salary,ravi.salary);
     cout<< ravi.nick_name ;
     cout<< endl<< shanu.nick_name ;
}
/*
all data types
Integer,Character,Boolean,Floating Point,double floating point,Valueless or Void,Wide Character
Function,Array,Pointer,Reference
Enumeration,Structure,Union,Typedef defined Datatype,Class
*/