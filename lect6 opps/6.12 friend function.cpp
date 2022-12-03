// bascially friend function has power to access the private data 


//f riend function is not a member function
// member function means eg set_data() , get_data() are member function
// we can write akshat.set_data() , this is function in which we write akshat.set_data() type thing is called member function 
// we if let asdf is a friend function then we can not write akshat.asdf() 


// friend function is a normal function which we studied earlier 
// if just have some power that it will access the private values of a class 
 
 
 #include <bits/stdc++.h>
using namespace std ;

class cmplex{
    private :
        int realpart ;
        int imgpart ;
    public :
        friend cmplex  sumnum (cmplex a , cmplex b) ;
        void set_value ();
        void get_value();
};

void cmplex :: set_value(){
    cout<<"write the real part "<< endl ;
    cin>> realpart ;
    cout<<"write the img part "<< endl ;
    cin>> imgpart ;
}
void cmplex :: get_value(){
    cout<< realpart <<"+"<<imgpart<<"i"<< endl ;
}

cmplex sumnum(cmplex a , cmplex b){
    cmplex c ;
    c.realpart =(a.realpart + b.realpart) ;
    c.imgpart = (a.imgpart+b.imgpart) ;
     return c ;
}
//we cant do this type of things in normal function means we cant access the private values
// access private values means a.realpart ,b.realpart ... etc 
// for doing operation on private values friend function is a very important tool 
// we can do operation without friend function also but it will bit tougher then this  



int main(){
    cmplex s,d,suj ;
    s.set_value() ;
    d.set_value() ;
    suj = sumnum(s,d) ;
    suj.get_value();

}


/* Properties of friend functions
1. Not in the scope of class
2. since it is not in the scope of the class, it cannot be called from the object of that class. c1.sumComplex() == Invalid
3. Can be invoked without the help of any object
4. Usually contans the objects as arguments
5. Can be declared inside public or private section of the class
6. It cannot access the members directly by their names and need object_name.member_name to access any member.

*/
