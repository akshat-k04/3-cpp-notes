#include <bits/stdc++.h>
using namespace std ;

int main(){
    vector<int> a ;
    a.push_back(1) ;
    a.push_back(2) ;
    a.push_back(3) ;
    a.push_back(4) ;
    auto it = a.begin() +3 ;

    // 1. to find the min element of the vector
    int m = *min_element(a.begin(),a.end()) ;

    //2. for maximum 
    int k = *max_element(a.begin(),a.end()) ;

    // 3. to find sum of all element of vector
    int sum = accumulate(a.begin(),a.end(),0) ; // 0 is the ini value of sum

    // 4. count the number of time the number occours
    int counter = count(a.begin(),a.end() ,2);

    // 5. reverse the vector
    reverse(a.begin(),a.end()) ;

    // 6. to erase the element
    a.erase(a.begin()+2) ;

    // 7. to clear the vector
    a.clear() ;

    //O(n) is the time complexity for all the above operation
}