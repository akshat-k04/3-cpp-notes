/*
************reference operator***********/
 #include <bits/stdc++.h>
using namespace std ;
void cpy(vector<int> v){
    v.pop_back();
    v.pop_back();
    v.pop_back();
    // we do 3 times pop back due to which the size of v become 1 
    // but the size of fg is 4 it will not change neighter the elements are remove
    cout<<"the size of v is "<< v.size();
}

int transfr(vector<int> &l){
    l.pop_back();
    l.pop_back();
    l.pop_back();
    cout<<"the size of l is "<< l.size();
}
int main(){
    vector<int> fg(4,5);
    cpy(fg);
    // the cpy function will take input of a vector 
    // we give fg vector as input 
    // it doesnt mean that all operation in function are done on the vector fg 
    // bascically a a copy of fg i.e. is made on which all operation are done
    cout<<"the size of fg vector is"<<fg.size();


    transfr(fg);
    //the transfr function we made will take input of vector 
    // the we use & operator , it means we transfer the vector 
    //we transfer the vector , not copy it 
    //vector in int main function is called as fg , where as in transfr function it is called as l 
    // what ever operation we do in transfr function will done on this fg vector 
    // conclusion:- we have only 1 vector jus tname is diff.
    cout<<"the sze of fg is "<< fg.size();


    // let make here one reference vector 
    vector<int> &df=fg ;
    // the above line means just that we gave one more name to vector fg that is df
    // we can use eighter df or fg to do operation here changes will be done on fg vector
    //eg:
    df.pop_back();
    cout<<"the sze of fg is "<< fg.size();





}