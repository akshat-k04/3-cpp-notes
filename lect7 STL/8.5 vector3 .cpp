 #include <bits/stdc++.h>
using namespace std ;

template <class T>
void print (vector<T> &vect){ // here we write t instead of data type because we want to use this function for any data type vector 
// that is why we do template <class T>
    int p = vect.size();
    for(int r=0 ; r<p ; r++){
        cout<< vect.at(r) ;
    }
}

int main(){
    vector<int> vect(6,2) ;
    // we make the vector whose size is 6 and has number 2 only in each block
    vector<char> vect1 ;
    vect1.push_back('1') ;
    print(vect) ;
    print(vect1) ;
}