//solved
// link:- https://www.interviewbit.com/problems/search-in-bitonic-array/

//approch 1 :-


#include <bits/stdc++.h>
using namespace std ;
typedef vector<int> vii;
#define pb push_back

int main (){
    int n;
    cin>> n ;
    vii a ;

    for(int e=0 ;e<n ; e++){
        int h ;
        cin>>h ;
        a.pb(h) ;
    }
    //input is done

    int ini=0 , lst= n-1 ;
    int mid=(ini+lst)/2 ;
    // mid==ini || mid== lst ||( a[mid]>a[mid-1] && a[mid]<a[mid+1])||( a[mid]>a[mid+1] && a[mid]<a[mid-1])
    while(lst-ini>1){
        mid=(ini+lst)/2 ;
        if(( a[mid]>a[mid-1] && a[mid]<a[mid+1])){
            ini=mid ;
        }
        else{
            lst = mid ;
        }
    }
    // index lst is the index of largest number

    int b ;
    cin>> b ;
    int indx1 = lower_bound(a.begin(),a.begin()+lst+1,b) - a.begin() ;
    int indx2 = n-1- (lower_bound(a.rbegin(),a.rbegin()+n-lst,b) - a.rbegin()) ;
    cout<<*(a.rend()-1)<<endl ;
    cout<<indx2<<endl ;
    // if(a[indx1]== b){
    //     cout<<indx1<<endl ;
    // }
    // else if(a[indx2]==b){
    //     cout<<indx2<<endl ;
    // }
    // else{
    //     cout<<-1<<endl ;
    // }
}









//approch 2 :- 

//  #include <bits/stdc++.h>
// using namespace std ;
// int main(){
//     int n ;
//     cin>> n ;
//     vector<int> a(n) ;
//     for(int e=0 ;e<n ;e++){
//         cin>> a[e] ;
//     }
//     int b ;
//     cin>>b ;
    
//     int ini =0 ,finl =n-1 ,mid ;
//     mid = ini+finl ;
//         mid/=2 ;
//     while(!(a[mid]>a[mid-1]&& a[mid]>a[mid+1] )&& ini<=finl){
//         mid = ini+finl ;
//         mid/=2 ;
//         if(a[mid]>a[mid-1] && a[mid]<a[mid+1]){
//             ini=mid+1 ;
//         }
//         else if(a[mid]<a[mid-1] && a[mid]>a[mid+1]){
//             finl =mid-1 ;
//         }

//     }
//     // cout<< mid <<endl ;
//     // we found place of greatest term 
//     if(b>a[mid]){
//         cout<<-1<<endl ;
//     }
//     else if(b==a[mid]){
//         cout<< mid<<endl ;
//     }
//     else {
//         int newFinal = mid ;
//         ini = 0 ;
//         int newMid  ;
//         int posi =-1 ;
//         while(newFinal-ini>1){
//             newMid = newFinal+ini ;
//             newMid/=2 ;
//             if(a[newMid]>b){
//                 newFinal = newMid ;
//             }
//             else if(a[newMid]<b){
//                 ini = newMid ;
//             }
//             else {
//                 posi = newMid ;
//                 break ;
//             }
//         }
//         if(a[ini]==b){
//             posi=ini;
//         }
//         else if(a[newFinal]==b){
//             posi= newFinal;
//         }
//         if(posi ==-1){
//             ini = mid ;
//             newFinal = n-1 ;
//             while(newFinal-ini>1){
//                 newMid = newFinal+ini ;
//                 newMid/=2 ;
//                 if(a[newMid]>b){
//                     ini = newMid ;
//                 }
//                 else if(a[newMid]<b){
//                     newFinal = newMid ;
//                 }
//                 else {
//                     posi = newMid ;
//                     break ;
//                 }
//             }
//         }
//         cout<<posi<<endl ;
//     }
// }