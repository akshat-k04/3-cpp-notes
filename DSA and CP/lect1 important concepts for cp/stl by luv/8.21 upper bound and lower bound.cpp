 #include <bits/stdc++.h>
using namespace std ;
int main(){
// upper bound and lower bound

/*
lower bound :- it will return the address of the number we want to find 
if that is not prsent then it will return the address of number wich is prsent and just greater than the input number

upper bound:- it will return the number which greater then the input number irrespective that the number is present or not'

for using this we need to dort the arry first 
other wise the time- complexity will be o(n) ; and also the ans will be wrong 
// because it assume that the array is sorted
if array is sorted then the time complexity is o(log(n))

*****for this array must be sorted*******
*/
    int n ;
    cin>> n ;

    // for array
    // int a[n];
    // for(int e=0 ; e<n ;e++){
    //     cin>> a[e] ;
    // }
    // sort(a, a+n);
    // int *pt = lower_bound(a, a+n ,6);
    // // this a,a+n  is the position that from where to where we need to find 
    // cout<<*pt<< endl ; // 6 is prsent then it will be printed else then next greater number 




    // for vector 

    // vector<int> a ;
    // for(int e=0; e<n ;e++){
    //     int h ;
    //     cin>> h ;
    //     a.push_back(h);
    // }
    // sort(a.begin(), a.end());

    // auto it = upper_bound(a.begin(),a.end(),6 );
    // cout<<*it << endl ;


    //maps,sets 

    map<int,int> a ;
    for(int e=0 ; e<n ; e++ ){
        int h ,k ;
        cin>> h>> k ;

        a[h]=k ;
    }

    auto it = a.lower_bound(5) ; // this 5 is key we used this for key
    // case of maps and sets we have to use a.lower_bound and same with upper bound 




     
}