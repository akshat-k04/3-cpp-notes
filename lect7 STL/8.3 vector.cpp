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
    //syntax of defining a vector
    vector<int> vect1 ;
    //  vector is just like array for more details see previous file
    for(int r=0 ; r< 4 ; r++){
        int ele ;
        cin>> ele ;
        vect1.push_back(ele) ;
        // the above line is used to add number in vector

    }
    // now we print how many number we store in vector
    cout<<vect1.size() ;
    //we add the elements now its time to print it 
    for(int e=0 ; e<vect1.size() ; e++){
        cout<< vect1[e]<<" " ;
        // this is how we can print the numbers stored in vector
    }
    // now lets make a function to print the elements 
    //print (vect1);

    // if i want to add a number then do this

    vector<int> :: iterator ite = vect1.begin() ;
    // we make a iterator ite  which point on 1st element of vect1 vector

    //vect1.insert(ite,555) ;
    // the above line will insert the number 555 where ite will point 
    // rest all will be shift towards right by 1 


    //vect1.insert(ite+1,456) ;
    // this will insert number one place after the ite will point i.e. 456 is put at index =1 ;
    vect1.insert(ite ,5,0);
    // it means insert 0 , 5times 
    print (vect1) ;

}
/*
function we can use 

capacity
1. cout<<vect1.size();
we get number of nubers in that vector

2. cout<<vect1.max_size();
Returns the maximum number of elements that the vector can hold.
may be 1lakh, 50k etc

3. vect1.resize(7,19)
it means that if it has 10 elements initially then remove last 3 elements only 
but if it has 6 or less elements then make that vector of size 7 and on additional space store 19
if we write vect1.resize(7) this then by default they store 0 on that space

4. myvector.empty()
Return Value:-true if the container size is 0, false otherwise.

5. and many more ...
go to https://m.cplusplus.com/reference/vector/vector/
for more info

*/