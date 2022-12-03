// just like structure we have union
// but the diff is that in union we can set the data of object of only one type se the codes
 #include <bits/stdc++.h>
using namespace std ;
union Student 
{
    int age ;
    int salary ;
};
int main(){
    union Student akshat,garvit ;
    akshat.age = 89 ;
    akshat.salary=90 ;
    cout<< akshat.age ;
    cout<< endl<<akshat.salary ;
    // in union we only can take one of the data for object 
    // as we see fro output 

}
