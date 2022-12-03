 // map is the container which store the key , value pair 
    //similar as dictionary in python

    /* we have 3 types of maps 
    1. normal maps 
    2. unordered maps
    3. multi maps 

    when we put the pairs in normal map then the pairs are stored in the sorted order on the basis of keys of the pairs
    in unordered maps pairs are in order as we give input 
    */ 


 #include <bits/stdc++.h>
using namespace std ;
int main(){
    // let us define the normal map
    map<int,string > m ;
    // the data type of key is int and value has string
    // now lets insert the pair 
    m[1]="asd"; // key is 1 and value is asd 
    m[6]="dfg"; // key is 6 and value is dfg
    m.insert({3,"tyu"}) ;// key is 3 and value is tyu
    
    //we give input in order of key as 1,6,3
    // lets see is is sorted or not

    //approch1 for printing 
    cout<<"first method"<< endl ;
    map<int, string> :: iterator ite = m.begin(); // we can do:- auto ite = m.begin()
    for(;ite!=m.end();ite++){
        cout<<(*ite).first <<" "<<(*ite).second;
        cout<< endl ;
    }
    
    // aproch2 for printing 
    cout<<"\nsecond method"<<endl ;
    for(auto val : m){
        cout<<val.first <<" "<< val.second<<endl ;
    }

    // size of map
    cout<<"the size is "<<m.size()<< endl  ;

    // if we write 
    m[10] ;
    //then by default value of key =10 stored as empty string
    // if value has data type int then by default value stored is 0
    // vector is data type of value then default value will be empty vector 


    /*
    ******imp******
    all the key of map will eb unique 
    let suppose we do m[5]="asd"
    then again we do m[5]="dfg"
    then the value stored corrosponding to key=5 will be dfg and not asd
    */

    /* time complexity 
    for taking the output of all pairs of map the time complexity will be n logn
    for insertion of a single pair in map whose size is n is logn
    */

    // lets find the value of key 
    map<int, string> :: iterator it ;
    it = m.find(3) ; // this line will point the iterator it to pair of key=3
    // time complexity of the find operation is logn
    cout<<(*it).second <<endl ;


    // lets erase the pair
    auto te = m.find(3) ;
    m.erase(it);
    cout<<m.size() ;


    // lets clear all the element 
    //m.erase() ;
    cout<< m.size() ;
}