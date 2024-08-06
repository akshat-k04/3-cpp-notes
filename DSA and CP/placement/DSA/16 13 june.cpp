// https://leetcode.com/problems/trapping-rain-water/
// best = O(n) O(1) 
// my = O(n) O(n)

class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size() ;
        vector<int> left_d(n), right_d(n) ;

        int max_h =0 ;
        for(int e=0 ;e<n ;e++){
            if(max_h<h[e])max_h= h[e] ;
            left_d[e] = max_h-h[e] ;
        }
        max_h =0 ;
        for(int e=n-1 ;e>=0 ;e--){
            if(max_h<h[e])max_h= h[e] ;
            right_d[e] = max_h-h[e] ;
        }
        int ans =0 ;
        for(int e=0 ;e<n ;e++)ans+= min(left_d[e],right_d[e]) ;
        return ans ;
    }
};