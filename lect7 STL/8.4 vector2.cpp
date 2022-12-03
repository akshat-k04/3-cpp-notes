 #include <bits/stdc++.h>
using namespace std ;
void print(/*just like we write int / float here in the same way we have to write "vector<int>" if we want to use vector in it */ vector<int> v  ){
    cout<<"\nwe are using the function to print it " ;
    int i =v.size() ;
    for(int w=0 ;w<i ; w++){
        cout<< v[w]<< " ";
    }
}



int main(){
    vector<int> vect ;
    /*
    for(int e =0 ; e< 5 ; e++){
        int h ; 
        cin>> h ;
        vect.push_back(h);
    }
    // now we will print the vector
    for(int e=0 ; e<5 ; e++){
        //cout<<vect[e]<<" "; or we can do
        cout<< vect.at(e) ;
    }
    */





    // different ways of defining a vector
    vector<char> vec(4) ; // 4 element character vector but at present it is empty
    vector<char> vectcopy(vec) ; // it is the copy of vec ;
    vector<int> vectzero ; // it is a vector of 0 size 
    // this vector does not contain any value if we print we not get any thing 
    // if we want to add default value to it do 
    //vectzero.push_back(0) ;
    
    vector<int> :: iterator it = vectzero.begin() ;
    vectzero.insert(it , 2, 1) ;// means add 0 , 500 times at the begining 
    //print(vectzero);
    // or if we want to add default value do 
    vectzero.resize(10); // now vectzero has size 10 
    // where 1st 2 numbers are 1 then rest all are 0 ;
    print (vectzero) ;
}