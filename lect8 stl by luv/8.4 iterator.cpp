// iterator is will point some element
 // the iterator which point the first index is called as .begin() iterator
 //iterator which point the space next to the  last index is called .end() iterator
 /*
 1 2 3 4 5
 ^        ^
 begin    end iterator*/
 //v.begin() point v[0] 
 //v.end() point v[last index] +1

  #include <bits/stdc++.h>
 using namespace std ;
 int main(){
    vector<int> ::iterator it;
    //we make a iterator
    // but at present it will not point any thing

    vector<int> v(5,2) ;
    it=v.begin();
    //it will point the 1st index of v
    cout<<*it<<endl ;
    //we get the first value of v[0]
    cout<<*(it+1)<<endl ;
    // give value of v[1] 
   
    // it like a pointer but the difference is that iterator will only point it will not store the address of that place
    // but pointer will store the address of place 
    //eg :- let a is pointer variable cout<<a; gives us address , cout<<*a; gives us the value stored in the address stored in the pointer variable a
    // eg. :- let it be a iterator then cout<<it: give error because it does not store any value or address but cout<<*it; will give the value where it point


    /*we can also declear a iterator for a pair 
    do 
    vector<pair<int,int> > :: iterator ite ;
    cout<<*ite ; qut put we get is pair
    cout<<(*ite).first give 1st value 
     */

   /*when we use for loop for iterator and we use update as it+=1 
     it means that it iterator will move to the next location in the memory 
     where as if we do it++ it means that it will move to the next location of the container(can be vector , maps , sets etc)
     */
 }
