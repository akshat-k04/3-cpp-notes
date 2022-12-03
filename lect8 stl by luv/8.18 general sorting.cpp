 #include <bits/stdc++.h>
using namespace std ;
bool shouldSwap(pair<int,int> a , pair<int,int> b){
    if(a.first!=b.first){
        if(a.first>b.first){
            return true ;
        }
        else {
            return false ;
        }
    }
    else {
        if(a.second<b.second){
            return true ;
        }
        else {
            return false ;
        }
    }
}

int main(){
    //method 2

    int n ;
    cin>> n ;
    pair<int, int> a[n] ; 
    for(int e=0 ;e<n ;e++){
        int h ;
        cin>>h ;
        int k ;
        cin>>k ;
        a[e]=make_pair(h,k);
    }
    for(int e=0; e<n;e++){
        for(int j= e+1 ; j<n ; j++){
            if(shouldSwap(a[e],a[j])){
                swap(a[e], a[j]);
            }
        }
    }
    for(int e=0 ; e<n ;e++){
        cout<<a[e].first<<" "<<a[e].second<<endl;
    }
}


/*
    int n ;
    cin>>n ;
    int a[n];
    for(int e=0; e<n;e++){
        cin>>a[e];
    }


    //method 1

    for(int e=0; e<n;e++){
        for(int j= e+1 ; j<n ; j++){
            if(a[e]>a[j]){
                swap(a[e], a[j]);
            }
        }
    }
    for(int e=0 ; e<n ;e++){
        cout<<a[e]<<" ";
    }
*/