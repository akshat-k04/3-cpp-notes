/*
map
unordered map
multi_map
Operation	Map	Unordered Map	MultiMap
  Insert	O(log n)	O(1)	O(log n)  (direct we can add)
  Remove	O(log n)	O(1)	O(log n)  (myMap.erase(key);)
    Find	O(log n)	O(1)	O(log n)  (mp[key])
    Size	O(1)	    O(1)	O(1)      (mp.size())
    Empty checkO(1)	    O(1)	O(1)      (mp.empty()) it return bool
Iterate through elementsO(n)	O(n)	O(n)


-------if i want to just find the key weather it is present or not in map than us mp.find(key) 
if it is present iterator point there else iterator point on mp.end() ;-------------
similar for set also
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
        // or i can use
        cout<<it->first<<" "<<it->second<<endl ;
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