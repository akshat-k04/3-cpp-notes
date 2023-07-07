/*
we have 3 types of set
1. ordered set or simply set
2. unordered set
3. multi set

Set: A Set is a collection of unique elements where each element can only appear once, ensuring there are no duplicates.
Multiset: A Multiset is a collection of elements where multiple occurrences of the same element are allowed, allowing for duplicates within the set.
Operation	             Set	Unordered Set	Multiset
              Insert	O(log n)	O(1)	O(log n)
              Remove	O(log n)	O(1)	O(log n)
                Find	O(log n)	O(1)	O(log n)
               Count	O(log n)	O(n)	O(log n)
                Size	O(1)	    O(1)	O(1)
         Empty check	O(1)	    O(1)	O(1)
Iterate through elementsO(n)	    O(n)	O(n)


it should be noted that finding and removing the element from unordered _seet is O(1)
*/
#include <bits/stdc++.h>
using namespace std ;
int main(){

    set<string> s ;
    s.insert("abd");
    s.insert("sdcd");
    s.insert("sdc");
    //time complexity is log(n) 
    //now if we want to find the address of abd then do this 
    
    
    
    cout<<"****for looop****"<<endl ;
    for(string value:s){
        cout<<value<<endl ;
    }

    cout<<"****now we use iterator****"<< endl;
    // lets find the position using the iterator 
    auto ite= s.find("abd");
    cout<< *ite<<endl ;


    cout<<"****lets erase the values****"<<endl;
    s.erase(ite);
    //or we can  do ("abd") instead of (ite)
    for(string value:s){
        cout<<value<<endl ;
    }
}
