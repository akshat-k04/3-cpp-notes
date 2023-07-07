 #include <bits/stdc++.h>
using namespace std ;
int main(){
    /*
    begin()	 :-This function returns an iterator to the beginning of the string.
    end()	:-This function returns an iterator to the end of the string.
    rbegin():-	This function returns a reverse iterator pointing at the end of the string.
    rend()	:-This function returns a reverse iterator pointing at beginning of the string.*/
    string aksa ;
    aksa = "hello world" ;
    cout<< aksa ;
     string::iterator f;
     for(f = aksa.begin(); f!=aksa.end(); f++){
        cout<< *f ;
     }
     string::reverse_iterator g;
     for(g=aksa.rbegin();g!=aksa.rend();g++){
        cout<< *g ;
     }

     string string1 = "Geeks.\nFor.\nGeeks.\n"; // \n are operated and we get the  output as we expect 
     string string2 = R"(Geeks.\nFor.\nGeeks.\n)"; // here outpur is Geeks.\nFor.\nGeeks.\n
     // here \n is considered as a character and nothing more than that 

}