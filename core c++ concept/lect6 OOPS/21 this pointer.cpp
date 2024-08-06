
/*
“this” is a keyword that is an implicit pointer. “this” pointer points to the 
object which calls the member function. An example program is shown below to 
demonstrate the concept of “this” pointer.
*/

class A{
    int a;
    public:
         A & setData(int a){
            this->a = a;
            return *this;
        }

        void getData(){
            cout<<"The value of a is "<<a<<endl;
        }
};

int main(){
    A a;
    a.setData(4).getData();
    return 0;
}
