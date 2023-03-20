//fiboncii in tabulation


//in preev file the time complexity is O(n) ans space complexity is also O(n) 
// here we try to decresae the space complexity to const i.e.O(2) 

 #include <bits/stdc++.h>
 
using namespace std ;

int solve(int t,int & prev1 ,int&prev2){
    int present = 0 ;
    for(int e=2 ;e<= t ;e++){
        present = prev1+prev2 ;
        prev2= prev1 ;
        prev1 = present ;
    }
    return (t>=2)? present:t ;
}


int main(){
    int t;
    cin>>t ;
    int prev1 = 1 , prev2 = 0 ;
    cout<<solve(t,prev1,prev2) ;
}