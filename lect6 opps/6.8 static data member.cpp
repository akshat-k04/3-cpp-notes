 #include <bits/stdc++.h>
using namespace std ;

class shop{
    int id[100] ;
    int price[100] ;
    int counter ;
    public :
        void set_id_and_price (int d);
        void initcount();
        int getprice(int a);
};


void shop:: set_id_and_price(int d){
    for(;counter<d;){
        cout<<"write the id of product"<< endl ;
        cin>> id[counter] ;
         
        cout<<"write the price of product"<< endl ;

        cin>> price[counter] ;
    
        counter ++ ;
    }
}


int shop:: getprice(int a){ //this a is id of product
    int index=-1 ; 
    for(int i=0 ; i<100; i++){
        if(id[i]==a){
            index= i ;
        }
    }
    if(index==-1){
        cout<< "no such id exist"<< endl ;
        return -1 ;
    }
    else{
        return price[index] ;
    }
    
}

void shop :: initcount(){
    counter =0 ;
}




int main(){
    shop biscuits ;
    cout<< "how many biscuits you want to do entry"<< endl ;
    int s ;
    cin>> s ;
    biscuits.initcount() ;
    biscuits.set_id_and_price(s) ;
    cout<<"if you have searched then write 999 to close the program\n" ;
    int i;
    for(;true;){
        cout<<"enter id of product\n";
        int a ;
        cin>> a ;
        if(a==999){
            break;
        }
        else{
            cout<<"the price is "<<biscuits.getprice(a)<<endl ;
        }
    }

}


//in the above program we use counter
/* at 1st we run initcount to initilize the counter=0 ,
then we run our program 
if we have 2 object and we want to use continious counter variable value 
then we use static data member 
which we discussed in next file */