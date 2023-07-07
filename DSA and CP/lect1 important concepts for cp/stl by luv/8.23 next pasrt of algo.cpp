 #include <bits/stdc++.h>
using namespace std ;


bool ispositive(int e){
    if(e>0){
        return true ;
    }
    else{
        return false ;
    }
}

int main(){
    int n ;
    cin>>n ;
    vector<int> a(n); 
    for(int e=0 ; e<n ;e++){
        cin>>a[e];
    }

// all_of() this will return a bool value 
    cout<<all_of(a.begin(), a.end(),ispositive) ;
    // from begin to end all value give true on input to ispositve function then the all_of function will return true
    // else it will return false 


// any_of()
    // here if atleast 1 will return true then any_of will return true 


// none_of()
    // if all value return false then only the none_of() will return true 
}