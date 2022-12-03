//here we explain the static variable
/*When a data member is declared as static , 
only one copy of the data is maintained for 
all objects of the class. Static data members 
are not part of objects of a given class type.*/


 #include <bits/stdc++.h>
using namespace std ;

class employee{
    static int counter  ;
    int id ;
    int salary ;
    public :
        void set_id();
        void set_price ();
        int get_counter ();
        int  init_count() ;
};

int  employee:: init_count (){
    cout<< "put the value of counter "<< endl ;
    int e ;
    cin>> e ;
    counter =e ;
    return counter ;
}

void employee:: set_id(){
    
}
void employee:: set_price(){

}
int  employee:: get_counter(){
    return counter ;
}




int employee:: counter ;
// by default the value of static variable is 0 ;
// if we want to  change it then just write 
// int employee:: counter=1000 ; 
//instead of 
// int employee:: counter ;





int main(){
    employee a,b,c ;
    a.init_count();
    cout<< a.get_counter()<<" "<< b.get_counter()<<" "<< c.get_counter()<< endl ;

}
// we get same value of 3 
// and this is the static variable where 
//we have to define value once then all object will get same value 
// the updation on any one object  will done on all 