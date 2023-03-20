//not done


// There are two sorted arrays A and B of size m and n respectively.

// Find the median of the two sorted arrays ( The median of the array formed by merging both arrays ).

// The overall run time complexity should be O(log (m+n)).

// NOTE: If the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element. For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5 


// Problem Constraints
// 0 <= |A| <= 106
// 0 <= |B| <= 106
// 1 <= |A| + |B| <= 2 * 106


// Input Format
// The first argument is an integer array A.
// The second argument is an integer array B.


// Output Format
// Return a double value equal to the median.


// Example Input
// A : [1 4 5]
// B : [2 3]


// Example Output
// 3


// Example Explanation
// Merged A and B will be : [1, 2, 3, 4, 5]
// Its median will be 3


 #include <bits/stdc++.h>
using namespace std ;



int main(){
    int p,q ;
    cin>>p>>q ;
    vector<int>a(p) ,b(q) ;
    for(int e=0 ;e<p ;e++){
        cin>>a[e] ;
    }
    for(int e=0 ;e<q;e++){
        cin>>b[e] ;
    }
    //input is done
    int median =p/2 +1 ;
    int ini = 0, fnl = p-1 ;
    int mid  ;
    int indx ;
    while(fnl-ini>1){
        mid = (ini+fnl)/2 ;
        if(median-mid-1<=0){
            fnl = mid ;
        }
        
        else {
            indx = median-mid-2 ;
            if((mid>=p-1||b[indx]<=a[mid+1]) && (indx>=q-1||a[mid]<=b[indx+1])){
                break ;
            }
            else if(b[indx]>a[mid+1]){
                ini=mid ;
            }
            else if(a[mid]>b[indx+1]){
                fnl = mid ;
            }
        }
    }
    if(fnl-ini>1){
        //mid is used
        if((p+q)%2==0){

        }
        else{
            cout<<max(a[mid], b[median-mid-2])<<endl;
        }
    }
    else{
        indx = median - ini -2 ;
        if(a[ini]<=b[indx+1]&& (mid>=p-1||b[indx]<=a[ini+1])){
            if((p+q)%2==0){

            }
            else{
                cout<<max(a[ini],b[indx])<<endl ;
            }
        }
        else{
            indx = median - fnl -2 ;
            if((p+q)%2==0){

            }
            else{
                cout<<max(a[fnl],b[indx])<<endl ; ;
            }
        }
    }
}