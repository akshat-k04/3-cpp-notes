#include <bits/stdc++.h>
using namespace std ;

class classX{
    private :
        string phone ;

    public:
        int age ;
        static int clas ; 
        // as we use static so only one time memory is allocate and 
        // all object have same value 

        string surname ;
        string rollno ;
        string getphone(){
            return phone ;
        } // member function used to access the private values
        void update(string tp){
            phone=tp ;
        }

};

int classX :: clas =10 ;
int main(){
    classX akshat,garvit ;
    garvit.clas=20 ;
    cout<<akshat.clas ; //output :-20    
    // as already discussed
    akshat.update("6267366080") ;
    cout<<akshat.getphone() ;
}