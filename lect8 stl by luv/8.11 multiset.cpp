 #include <bits/stdc++.h>
using namespace std ;
int main(){
    multiset<int> num ;
    // here we can insert the same element multi times 
    num.insert(1);
    num.insert(2);
    num.insert(1);

    for(auto val:num){
        cout<<val<<endl ;
    }
    //if duplicates are present then and we use iterator then the iterator we give info for 1st element 


    // all operations are log(n) 
}