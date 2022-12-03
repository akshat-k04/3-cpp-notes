 #include <bits/stdc++.h>
using namespace std ;

class shop{
    private:
        string name ;
        int price ;
    public :
        void set_name();
        void set_price();
        void get_price();
        string get_name ();
};


void shop:: set_name(){
    cout<<"please write the name"<<endl;
    string a ;
    cin>> a ;
    name =a ;
}

void shop::set_price(){
    cout<<"please write the price"<<endl;
    int a ;
    cin>> a ;
    price =a ;
}

string shop:: get_name(){
    return name ;
}

void shop:: get_price(){
    cout<< price ;
}








int main(){
    shop biscuit[10],soap[10],misc[10] ;

    cout<<"how mant biscuit product you want to register"<< endl ;
    int a ;
    cin>> a ;
    for(int t =0 ; t<a ; t++){

        biscuit[t].set_name() ;
        biscuit[t].set_price();

    }


    cout<<"how mant soap product you want to register"<< endl ;
    int b ;
    cin>> b ;
    for(int t =0 ; t<b ; t++){

        soap[t].set_name() ;
        soap[t].set_price();

    }

    cout<<"how mant misc product you want to register"<< endl ;
    cin>> b ;
    for(int t =0 ; t<b ; t++){

        soap[t].set_name() ;
        soap[t].set_price();

    }
    for(;;){

        cout<<"write catagory of product , write 999 2 times , if your search ends"<< endl ;
        string a ;
        cin>>a ;
        cout<< "write the name of product \n";
        string b ;
        cin>> b ;
        int index =-1 ;
        if(a=="biscuits"){
            for(int p=0 ; p<10; p++){
                if(biscuit[p].get_name()== b){
                    index = p ;
                }
            }
            if (index ==-1){
                cout<<"this product is currently unavailable\n";
            }
            else {
                biscuit[index].get_price();
            }

        }
        else if (a=="soaps"){
            for(int p=0 ; p<10; p++){
                if(soap[p].get_name()== b){
                    index = p ;
                }
            }
            if (index ==-1){
                cout<<"this product is currently unavailable\n";
            }
            else {
                soap[index].get_price();
            }

        }
        else if (a == "misc"){
            for(int p=0 ; p<10; p++){
                if(misc[p].get_name()== b){
                    index = p ;
                }
            }
            if (index ==-1){
                cout<<"this product is currently unavailable\n";
            }
            else {
                misc[index].get_price();
            }

        }
        else if (a=="999"){
            break ;
        }
        else {
            cout<< "\nproduct catagory is not available please write diff"<< endl ;
        }
    }
}