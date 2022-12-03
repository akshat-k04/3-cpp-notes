 #include <bits/stdc++.h>
using namespace std ;
int main(){
    unordered_set<string> s ;
    
    s.insert("hello");
    s.insert("boi");
    s.insert("hello");
    s.insert("ak");

    for(auto val:s){
        cout<<val<<endl ;
    }

    //time complexity id o(1) for all the operations 
    
}