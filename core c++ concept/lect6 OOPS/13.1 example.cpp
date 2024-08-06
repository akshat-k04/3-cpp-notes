//************note for static*********
// if make a static object then it means it will remain through out the 
// program till it runs so, distructor will executed after the main function ends
#include <bits/stdc++.h>
using namespace std  ;

class profile{
public:
    int money ;
    string surname ;
    string stat ;
    ~profile(){ // distructor
        cout<<"distructor called .it is static?"+stat<<endl ;
    }
    profile(){
        cout<<"constructor called "<<endl ;
    }
};

int main(){
    cout<<"main start"<<endl ;
    if(true){
        cout<<"inside if"<<endl ;
        profile ram ;
        ram.stat="no" ;
        static profile akshat ;
        akshat.stat="yes" ;
    }
    cout<<"outside if"<<endl ;

    cout<<"main end"<<endl ;
}
/* output
main start
inside if
constructor called 
constructor called 
distructor called .it is static?no
outside if
main end
distructor called .it is static?yes
*/