// lets discuss here sets 
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