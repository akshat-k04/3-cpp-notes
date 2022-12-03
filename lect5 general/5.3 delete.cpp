 #include <bits/stdc++.h>
using namespace std ;
int main(){
    // we can delete the pointer which is made by "new " operator
    // delete the pointer doesnt mean that h will be deleted it means that the int that is stored in the addressof h is deleted
    // do this 
    
    int* h= new int (56)  ;
    delete h ;
    
    cout<< h << endl ;
    cout<< *h<< endl ;
    cout<< &h << endl ; 

}