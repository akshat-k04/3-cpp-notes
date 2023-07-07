//solved
 // binary search is applied on monotonus function only 
// let us understand this with example of searching a element from sorted array

  #include <bits/stdc++.h>
 using namespace std ;
 int main(){
    int n ;
    cin>> n ;
    vector<int> a(n) ;
    for(int e =0 ; e<n ; e++){
      cin>>a[e] ;                                  
    }
    //let us find 4 is present or not and if 4 is present then on which position
    int iniSpace =0 , finalSpace = n-1 ;
    while(finalSpace-iniSpace>1){
      int e= (iniSpace+finalSpace)/2 ;
      if(a[e]>1){
         finalSpace=e ;
      }
      else{
         iniSpace = e ;
      }
      
    }
    if(a[iniSpace]==1){
      cout<<iniSpace<<endl ;
    }
    else{
      if(a[finalSpace]==1){
         cout<<finalSpace<<endl;
      }
      else {
         cout<<"not present"<<endl ; 
      }
    }
 }