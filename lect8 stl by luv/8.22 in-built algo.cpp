 #include <bits/stdc++.h>
using namespace std ;
int main(){
    int n ;
    cin>>n ;
    vector<int> a(n) ;
    for(int e=0 ; e<n ;e++){
        cin>> a[e] ;
    }

    // the vector is made 


//1.minimum element of the vector
    auto it = a.begin()+n ; // or we can use a.end() both are same
    int m= *min_element(a.begin(),it) ; // min_element will return the pointer that is why * is used 
    cout<<m<< endl ;


//2. maximum element of the vector 
    // we have same syntax but here we use max_element


//3. sum of elements of vector 
    int h = accumulate(a.begin()+1 , a.end(), 0) ;
    cout<< h<< endl  ;
    // we get the sum of elements from 2nd element to last element 
    //we write 0 at the last which means that before doing the sum the value of h is 0 


//4. want to count how many number of time that number come in vector
    int c = count(a.begin(),a.end(),0) ;
    cout<< c<< endl ;


// 5. reverse the vector 
    reverse(a.begin(), a.end()) ;
    // same thing we use for string also 


// all operatons are of o(n) time complexity
// if we want to use on array then use a,a+n instead of a.begin() , a.end()
}