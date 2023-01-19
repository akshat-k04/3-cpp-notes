/*
Given a bitonic sequence A of N distinct elements, write a program to find a given element B in the bitonic sequence in O(logN) time.

NOTE:

A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.


Problem Constraints
3 <= N <= 105

1 <= A[i], B <= 108

Given array always contain a bitonic point.

Array A always contain distinct elements.



Input Format
First argument is an integer array A denoting the bitonic sequence.

Second argument is an integer B.



Output Format
Return a single integer denoting the position (0 index based) of the element B in the array A if B doesn't exist in A return -1.



Example Input
Input 1:

 A = [3, 9, 10, 20, 17, 5, 1]
 B = 20
Input 2:

 A = [5, 6, 7, 8, 9, 10, 3, 2, 1]
 B = 30


Example Output
Output 1:

 3
Output 2:

 -1
*/


 #include <bits/stdc++.h>
using namespace std ;
int main(){
    int n ;
    cin>> n ;
    vector<int> a(n) ;
    for(int e=0 ;e<n ;e++){
        cin>> a[e] ;
    }
    int b ;
    cin>>b ;
    
    int ini =0 ,finl =n-1 ,mid ;
    mid = ini+finl ;
        mid/=2 ;
    while(!(a[mid]>a[mid-1]&& a[mid]>a[mid+1] )&& ini<=finl){
        mid = ini+finl ;
        mid/=2 ;
        if(a[mid]>a[mid-1] && a[mid]<a[mid+1]){
            ini=mid+1 ;
        }
        else if(a[mid]<a[mid-1] && a[mid]>a[mid+1]){
            finl =mid-1 ;
        }

    }
    // cout<< mid <<endl ;
    // we found place of greatest term 
    if(b>a[mid]){
        cout<<-1<<endl ;
    }
    else if(b==a[mid]){
        cout<< mid<<endl ;
    }
    else {
        int newFinal = mid ;
        ini = 0 ;
        int newMid  ;
        int posi =-1 ;
        while(newFinal-ini>1){
            newMid = newFinal+ini ;
            newMid/=2 ;
            if(a[newMid]>b){
                newFinal = newMid ;
            }
            else if(a[newMid]<b){
                ini = newMid ;
            }
            else {
                posi = newMid ;
                break ;
            }
        }
        if(a[ini]==b){
            posi=ini;
        }
        else if(a[newFinal]==b){
            posi= newFinal;
        }
        if(posi ==-1){
            ini = mid ;
            newFinal = n-1 ;
            while(newFinal-ini>1){
                newMid = newFinal+ini ;
                newMid/=2 ;
                if(a[newMid]>b){
                    ini = newMid ;
                }
                else if(a[newMid]<b){
                    newFinal = newMid ;
                }
                else {
                    posi = newMid ;
                    break ;
                }
            }
        }
        cout<<posi<<endl ;
    }
}