/*
all things functions are smae except 
1. time complexity is o(1) instead of lon n in order maps
2. they are not in sorted order
*/
 #include <bits/stdc++.h>
 #include <unordered_map>
using namespace std ;
int main(){
    unordered_map<int,int> m ;
    m[15]=10;
    m[5]=6 ;
    for(auto d : m){
        cout<<d.first<<" "<< d.second<< endl ;
    }
}