// it only and only use static variables 
// throws an error if we use normal variable 
 #include <bits/stdc++.h>
using namespace std ;

class employee{
    static int count ;
    int id ;
    public :
        static int get_count () ;
};

int employee :: get_count(){
    count ++ ;
    return count ;   
}
int employee:: count ;






int main(){
    employee akshat , garvit, aastha ;
    // to access the static we do not need object we can access it using class it self 
    // eg :- generally we do akshat.getdata() ;
    // here we can do employee:: get_count ;
    cout<<employee::get_count ()<< endl ;
    cout<<employee::get_count ();

}