 #include <bits/stdc++.h>
using namespace std ;
int main(){
    vector<int> vect(5,2) ;
    for(int value :vect){ // this will not only work for container vector only it will work for all the container 
        //bascically value of value is changes and occupied the next value of container after code execution in loop
        cout<<value<< " ";
    }
    cout<< endl ;


// now lets make a short code to define any object

   auto a=1.0 ;
   auto b= true ;
   auto c= 1 ;
   auto d = vect.begin() ;

   // this auto wil automatically define the data type of vearible on the basis of value given
   // a has float , bhas bool ,c has int , d has iterator 

}