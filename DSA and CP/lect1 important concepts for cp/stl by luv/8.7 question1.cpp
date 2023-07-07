/* 
given N strings , print unique strings in dictionary order with their frequency 
*/

 #include <bits/stdc++.h>
using namespace std ;
int main(){
    int n ;
    cin>> n ;

    map<string, int> m ;
    // hew we make a map in which key is string and value is int 
    // bascically we know that the keys are unique so when we take input of string and insert in the map
    // map will just modify the value as we see in previous files 
    // here we do modification by adding 1 
    // in this way we get the frequency of each string 
    for(int e=0 ; e< n ;e++){
        string s ;
        cin>> s; 
        m[s] +=1 ;

    }

    // lets print 
    for(auto y : m){
        cout<<y.first <<" "<< y.second<< endl ;
    }
}