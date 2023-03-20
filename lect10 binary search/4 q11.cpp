//solved 

// key concept:- here i divide a array in 2 part now check the relative posi of mid+e and mid-e with their naighour  and there relative also
//               if there is not favrable position then it means then it means we have to do operation on that and next all element

// You are given a permutation p
//  of length n
//  (a permutation of length n
//  is an array of length n
//  in which each integer from 1
//  to n
//  occurs exactly once).

// You can perform the following operation any number of times (possibly zero):

// choose two different elements x
//  and y
//  and erase them from the permutation;
// insert the minimum of x
//  and y
//  into the permutation in such a way that it becomes the first element;
// insert the maximum of x
//  and y
//  into the permutation in such a way that it becomes the last element.
// For example, if p=[1,5,4,2,3]
//  and we want to apply the operation to the elements 3
//  and 5
// , then after the first step of the operation, the permutation becomes p=[1,4,2]
// ; and after we insert the elements, it becomes p=[3,1,4,2,5]
// .

// Your task is to calculate the minimum number of operations described above to sort the permutation p
//  in ascending order (i. e. transform p
//  so that p1<p2<⋯<pn
// ).

// Input
// The first line contains a single integer t
//  (1≤t≤104
// ) — the number of test cases.

// The first line of the test case contains a single integer n
//  (1≤n≤2⋅105
// ) — the number of elements in the permutation.

// The second line of the test case contains n
//  distinct integers from 1
//  to n
//  — the given permutation p
// .

// The sum of n
//  over all test cases doesn't exceed 2⋅105
// .

// Output
// For each test case, output a single integer — the minimum number of operations described above to sort the array p
//  in ascending order.


 #include <bits/stdc++.h>
using namespace std ;
int main(){
    int t ;
    cin>> t ;
    for(int r=0 ;r<t ;r++){
        int n ;
        cin>>n; 
        vector<int> p(n+1) ;
        for(int e=0 ;e<n ;e++){
            int h ;
            cin>>h ;
            p[h]=e+1 ;
        }
        int ans =0 ;
        int midr ;
        int midl ;
        int limit ;
        if(n%2==0){
             midr = n/2+1 ;
             midl=n/2;
             limit = n/2 -1 ;
            // positions start from 1 to n 
            // now 
        }
        else{
            midl=n/2 +1 ;
            midr = midl ;
            limit = int(n/2) ;
        }
        for(int e=0 ; e<=limit ;e++){
            if(!(p[midr+e]>=p[midl-e]&& (e==0||(p[midl-e]<p[midl-e+1] && p[midr+e-1]<p[midr+e])))){
                ans=limit+1-e;
                break ;
            }
        }
        cout<<ans<<endl ;
    }
}