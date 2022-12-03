/* this code has certain mistake correct code is written in next file */


 #include <bits/stdc++.h>
 #include <string.h>
using namespace std ;


void biscuit () ;
void misc () ;
class shop{
    private:
        string item_name ;
        int price ;
    public :
        void set_name (string name ) ;
        void set_price (int a) ;
        string get_name ();
        int get_price () ;
};


void shop::set_name (string name ){
    item_name = name  ;
}
void shop::set_price (int a){
    price  =a ;
}
int shop::get_price (){
    return price ;
}
string shop::get_name (){
    return item_name ;
}



int main(){

    cout<< "do you want to register item , if yes type y else n "<<endl ;
    char yn ;
    cin>> yn ;
    if(yn=='y'){
        cout<<"which commodity item do you want to register" ;
        string commmodity ;
        cin>>commmodity;
        switch(commodity){
            case "biscuit": 
                biscuit();
                break ;       
            default : 
                misc();
                break ;
        }
    }
    else {
        cout<<"so you want to check price of product"<< endl << "if your search ends then write 000"<< endl ;
        string as="as" ;
        while (as!="000"){
            cout<<"write the name of product"<< endl ;
            cin>> as ;
            cout<< as.get_price <<" "<< as.get_name << endl ;
        }

    }
}
void biscuit (){
    char bis[10][8] ;
    cout<<"how many product you want to register upto 10 " << endl ;
    int a ; 
    cin>> a ;
    for(int i=0 ; i<a ; i++){
        cout<< "write the name of product" << endl ;
        cin>>bis[i] ;
        shop bis[i] ;
        bis[i].set_name(bis[i]);
        int pri ;
        cout<<"write the price of product\n" ;
        cin>> pri ;
        bis[i].set_price(pri) ;
    }
}


void misc(){
    char misc[10][8] ;
    cout<<"how many product you want to register upto 10 " << endl ;
    int a ; 
    cin>> a ;
    for(int i=0 ; i<a ; i++){
        cout<< "write the name of product" << endl ;
        cin>>misc[i] ;
        shop misc[i] ;
        misc[i].set_name(misc[i]);
        int pri ;
        cout<<"write the price of product\n" ;
        cin>> pri ;
        misc[i].set_price(pri) ;
    }

}
