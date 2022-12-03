/*
                             ****Why use classes instead of structures****
Classes and structures are somewhat the same but still, they have some differences. For example, we cannot hide
data in structures which means that everything is public and can be accessed easily which is a major drawback
of the structure because structures cannot be used where data security is a major concern. Another drawback of
structures is that we cannot add functions in it.


                                           ****Classes in C++****
Classes are user-defined data-types and are a template for creating objects. Classes consist of variables and
functions which are also called class members.


                                 ****Public Access Modifier in C++****
All the variables and functions declared under public access modifier will be available for everyone. They can
be accessed both inside and outside the class. Dot (.) operator is used in the program to access public data
members directly.

                                  ****Private Access Modifier in C++****
All the variables and functions declared under a private access modifier can only be used inside the class. They
are not permissible to be used by any object or function outside the class.
An example program to demonstrate classes, public and private access modifiers are shown in Code Snippet 1.
*/

#include <bits/stdc++.h>
using namespace std;

class employeeData
{
private:
    long int password;
    string userid;
    int salary ;
    int age ;

    // if we dont write private or public then by default compiler will take it private
public:
    void setPass(long int a);
    void setuserid(string b);
    string getid();
    long int getpass();
    void sal(int a) ;
};
void employeeData :: sal(int a){
    salary = a ;
}
void employeeData ::setPass(long int a)
{
    password = a;
}

void employeeData ::setuserid(string b)
{
    userid = b;
}
string employeeData::getid()
{
    return userid;
}
long int employeeData ::getpass()
{
    return password;
}

int main(){
        employeeData akshat, garvit;

    // introduce the details of the employee
    cout<< " enter the user id" ;
    string sd;
    cin >> sd;
    akshat.setuserid(sd);
    cin >> sd;
    garvit.setuserid(sd);

    long int set_pass;
    cin >> set_pass;
    akshat.setPass(set_pass);
    cin >> set_pass;
    garvit.setPass(set_pass);

// now the id and password is save
gl:;
    cout << "enter user id ";
    string enter_id;
    cin >> enter_id;
    long int req_pass;
    long int enter_pass;
    cin >> enter_pass;
    if (enter_id == akshat.getid())
    {
        req_pass == akshat.getpass();
    }
    else if (enter_id == garvit.getid())
    {
        req_pass == garvit.getpass();
    }
    
    if (enter_pass == req_pass){
        // do what ever operation you want to prossied 
        cout<< "hello user"<<endl ;
        int sala ;
        cin>> sala;
        akshat.sal(sala) ;
        cin>> sala ;
        garvit.sal(sala) ;
    }
    else
    {
        cout << "wrong password or id " << endl;
        cout<< "please try again"<< endl ;
        goto gl;

    }
}
