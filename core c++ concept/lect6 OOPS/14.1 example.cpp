/*
syntax of derived class 
class class_name : public_or_private base_class_name{
    //coding (public or private is called visibility mode)
}
NOTE:- 1. default visibility mode is private .
       2. public means:- public members of the base class becomes public members of derived class.
       3. private means:-public members of the base class becomes private members of derived class.
       4. NOTE:- private members of the base class never inherit in any case
       5. TO ACCESS THE PRIVATE MEMBER OF BASE CLASS MAKE PUBLIC MEMBER FUNC IN BASE CLASS AND THEN ACCESS
       6. when we create the object of deriveed class then that constructor will be called but also default constructor of base class will also called
       
*/

#include <bits/stdc++.h>
using namespace std ;



//base class
class employee {
    int salary ;
public :
    int employeeId ;
    employee(int id ,int sal){
        employeeId=id ;
        salary=sal ;
    }
    employee(){
        cout<<"default employee constructor"<<endl ;
    }
    void printsalary() ;
    void savesalary(int sal) ;
};
// class functions written here 
void employee :: printsalary(){cout<<salary<<endl ;}
void employee:: savesalary(int sal){salary=sal;}


//derived class
class programmers : public employee{
public:
    string programming_language ;
    string designation ; // web dev,app dev , backend dev 

    programmers(string lang,string defi,int id){ // set all 3 values
        cout<<"programmers constructor called"<<endl ;
        programming_language=lang ;
        designation=defi; 
        employeeId =id ;
    }
} ;



int main(){
    employee akshat(1,100)  ;

    /*
    create derived class object-->
    -->base clase constructor called (as it is called indirectly so explicit default will called)-->
    --->derived class constructor called 
    */

    programmers coder_harry("c++","web",1) ;
    coder_harry.savesalary(1000) ;
    coder_harry.printsalary();
}

/*
output:-
default employee constructor
programmers constructor called
1000
*/