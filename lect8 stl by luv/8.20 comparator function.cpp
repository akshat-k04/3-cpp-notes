 #include <bits/stdc++.h>
using namespace std ;

bool shouldSwap(int previous , int nxt ){
    if(previous>nxt){
        return true ;
    }
    else{
        return false ;
    }
}

int main(){
    int n ;
    cin>> n ;
    vector<int> a ;
    for(int e=0 ;e<n ;e++){
        int h ;
        cin>>h; 
        a.push_back(h);
    }

    // now lets sort the array according to our wish

//basic sort 


    // for(int e=0 ; e<n ;e++){
    //     for(int p=e+1 ; p<n; p++){
    //         if(shouldSwap(a[e],a[p])){
    //             swap(a[e],a[p]);
    //         }
    //     }
    // }

    






    /*
    *********** use the comparator function in in-built sort*********
    */

     sort(a.begin(),a.end(),shouldSwap);
     for(int e=0 ; e< n ;e++){
        cout<<a[e]<<" ";
    }
    cout<<endl ;
    // if add comparator function in the in-build sorting function then
    // if you want to swap then return us false 
    // if you dont want to swap then return true
}

// the function shouldSwap is called comparator function 
// what we wrtie there will affect the sorting algo 
// basically that is the logic
// we can sort the vector of pair according to our wish also 