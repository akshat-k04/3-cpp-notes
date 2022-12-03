//it is simply a continious memory block 
// whose size is dynamic 
//syntax:-
 #include <bits/stdc++.h>
using namespace std ;
int main(){
    vector<int> vect;
    // this is syntax of vector

    int x ;
    cin>> x;
    vect.push_back(x);
    //function push_back() is used to add the element in vector at the end  
    cout<<vect.size() ; //it will tell the size of vector


    vector<int> v(10,3);//the vector is formed whose size is 10 and value stored at all location is 3
    v.pop_back();// this will remove the last element


    // we can copy the vector like:
    vector<int> cpy=v ;
    //***********it should be know that the time complexity is o(n)


    


}