// https://leetcode.com/problems/product-of-array-except-self/?envType=study-plan-v2&envId=top-interview-150
// my = best = O(n) O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size() ;
        vector<int> ans ;
        ans.push_back(1) ;
        for(int e=1 ;e<n ;e++){
            ans.push_back(ans[e-1]*a[e-1]) ;
        }

        int temper = a[n-1] ;
        for(int e=n-2 ;e>=0 ;e--){
            ans[e] *= temper ;
            temper*= a[e] ;
        }
        return ans ;
    }
};