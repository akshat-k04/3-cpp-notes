/*
You are given a array of strings A of length N.

You have to return another string array which contains all possible special strings in Lexicographic order.
A special string is defined as a string with length equal to N, 
and ith character of the string is equal to any character of the ith string in the array A.
*/

  #include <bits/stdc++.h>
 using namespace std ;

vector<string> valid ;
 void generate(vector<string> &arr ,int k,string &temp ){
    for(int e=0 ; e<arr[k].length() ;e++){
        temp+=arr[k][e];
        if(k==arr.size()-1){
            valid.push_back(temp);
            //cout<<k<<endl ;
        }
        if(k<arr.size()-1){
            generate(arr, k+1 , temp);
        }
        temp.pop_back() ;
    }
 }


 int main(){
    int n ;
    cin>> n ;
    vector<string> arr(n) ;
    for(int e=0 ; e<n ;e++){
        cin>> arr[e] ;
    }
    // we took the input 
    int k =0 ;
    string temp="" ;
    generate(arr,k,temp);
    // printing 
    sort(valid.begin(),valid.end()) ;
    for(int e=0 ; e<valid.size();e++){
        cout<<valid[e] <<endl ;
    }
 }