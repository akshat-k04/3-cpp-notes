//pair is a class which store 2 data tyes 
//eg
 #include <bits/stdc++.h>
using namespace std ;
int main(){
    pair<int,string> p;
    // we make 1 pair whose name is "p"
    //"p" will store integer as 1st value and string as 2nd
    p=make_pair(2,"asd");
    //we stored the value
    //now we will print is 
    cout<<p.first<<" "<<p.second<<endl ;

    //lets make a copy of "p"
    pair<int,string> p1=p ;
    //p1 is a copy of p

    // WE can also make the array of pair 
    pair<int,string> fg[10];
    //array is formed
    // if can swap also by using swap()function as we do earlier
    

}