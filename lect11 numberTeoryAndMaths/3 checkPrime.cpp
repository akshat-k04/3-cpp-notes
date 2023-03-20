//not done

// here we need to find all the prime factor of a given number 

// for this i will use for loop till sqrt(a) ;
// if i find any b

 #include <bits/stdc++.h>
using namespace std ;

bool solve(int a){
    int b = sqrt(a) ;
    for(int e=2 ; e<=b ;e++){
        if(a%b==0){
            return false ; // means it is not prime
        }
    }
    return true ;
}

int main(){
    int a ;
    cin>> a ;
    string str =(solve(a))? "true": "false";
    cout<<str<<endl ;
}