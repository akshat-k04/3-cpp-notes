//done

 #include <bits/stdc++.h>
using namespace std ;


int hcf(int a , int b ){
    if(a%b==0){
        return b ;
    }
    else {
        return hcf(b, a%b) ;
    }
}
int main(){
    int a , b ;
    cin>> a>>b ;
    cout<< hcf(a,b) ;
}


//key idea 

// the key idea behind this hcf function is explained with the example
// let we have 7 and 10 we need to find the hcf 
// so let hcf is x 
// means x divides 7 and 10 both now so that we can say that 
// x must have to divide (10-7) also logical 
// hence we can say that x must divide (10%7) ;
// so if we want to maximize the x then find hcf of 7 and (10%7) 
// this is how this code is written