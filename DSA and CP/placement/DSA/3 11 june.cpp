// best time (n) space(1)
// my time (nlogn) space (1) --> best achived
https://leetcode.com/problems/remove-duplicates-from-sorted-array/?envType=study-plan-v2&envId=top-interview-150
// just copy pasted the 4 11june.cpp solution

class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size() ; // 6
        int ans =n ; // 6
        int i =0 ; //0
        for(int e= 0;e<n ;){ //0
            int j = e ; //0
            e++ ; //1
            while(e<n && a[j]==a[e])e++ ; //3
            e-- ; //2
            if(e-j+1>=1){
                ans-=(e-j-1-1) ; // 5
                a[i] = a[j] ; i++ ; //1
            }
            else {
                a[i] = a[j] ; i++ ;
            }
            e++ ;
        }
        return ans ;
    }
};