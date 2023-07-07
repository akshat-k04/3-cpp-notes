//solevd

 #include <bits/stdc++.h>
using namespace std ;

double eps = 1e-6 ;
int main(){
    double n ;
    cin>> n ;
    double ini =eps ,finl = n ,mid =0.0 ;
    while(abs(n-mid*mid)>eps ){
        mid = ini+finl ;
        mid/=2.0 ;
        if(mid*mid >n){
            finl = mid ;
        }
        else if(mid*mid<n){
            ini = mid ;
        }
        
    }
    cout<< mid <<endl;

}

//tiime complexity depend on presision 


// if want to find the cube root then just write mid*mid*mid similar for nth root