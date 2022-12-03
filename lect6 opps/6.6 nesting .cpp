/*              ****Object-Oriented programming Recap****
1.Stroustrup initially named C++ language as C with classes because C++ 
language was almost the same as C language but they added a new concept 
of classes in it.
2.Classes are the extension of structures in C language.
3.Structures had limitations such as; members are public and no methods.
4.Classes have some additional futures than structures such as; classes 
that can have methods and properties.
5.Classes have a feature to make class members as public and private.
6.In C++ objects can be declared along with class deceleration as shown 
in Code Snippet 1.
class Employee{
            // Class definition
} harry, rohan, lovish;
//Declaring Objects with Class Declaration
*/


 #include <bits/stdc++.h>
using namespace std ;


class dukaan{
    private :
        int price ;
        string id ; // name
    public :
         void setid(string a){
            id= a ;
         }
         string getid(){
            return id ;
         }
         void setprice(int a){
            price =a ;
         }
         void getprice(){
            cout<< price ;
         }
        
};
int main(){
    cout<<"want to add items write yes or no  "<< endl ;
    string ans ;
    cin>> ans ;
    if(ans=="yes"){
        cout<< "how many items you want to add"<< endl ;
        int num ;
        cin>> num ;
        dukaan NoOfItems[num];

        // this is the way we can create the array of object 
        
        string idset ;
        int price ;
        for(int u=0 ; u<num; u++){
            cout<<u+1<<"." <<"write the id of product"<< endl ;
            cin>>idset ;
            NoOfItems[u].setid(idset) ;
            cout<< "set the price of product id" ;//.getid() ;
            cout<< endl ;
            cin>> price  ;
            NoOfItems[u].setprice(price) ;
            cout<<"the item is stored in the database "<< endl;
            while(u==num-1){
                cout<<"write product id"<< endl;
                string writeid ;
                cin>> writeid ;
                for(int y=0 ; y<num ; y++){
                    string a=NoOfItems[y].getid() ;
                    if(writeid== a){
                        cout<<"the price is " ;
                        NoOfItems[y].getprice() ;
                        cout<< endl;
                    }
                }
            }
        }

    }
    
}