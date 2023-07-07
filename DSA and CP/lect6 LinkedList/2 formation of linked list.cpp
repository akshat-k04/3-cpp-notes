// int* a ;  means a will store the address of int 

// (*a).name is same as a->name  both are same


#include <bits/stdc++.h>
using namespace std ;

class node{
    public:
        int num ;
        node* nxtAddress ;

        void noder(int a){
            num = a ;
            nxtAddress = NULL ;
        };
};

int main(){
    // the linked list starts from the head 
    // so lets create the head 
     node* head ;
     
    // now lets insert the number in and make linked list 
    
}