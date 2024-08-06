// https://leetcode.com/problems/minimum-size-subarray-sum/?envType=study-plan-v2&envId=top-interview-150
// my = best = n,1 

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& a) {
        int n= a.size() ;
        int ini =0 , end =-1 ;
        int sum = 0 ;
        int ans = 1e9 ;
        while(end<n){
            while(end<n && sum<target){
                end++ ;
                if(end<n)sum+=a[end] ;
                if(sum>=target) ans = min(ans , end-ini+1) ;
            }
            
            while(ini<=end && sum>=target){
                sum-=min(a[ini],sum) ;
                ini++ ;
                if(sum>=target)ans = min(ans ,end-ini+1) ;
            }
            
        }
        return (ans==1e9)?0:ans ;
    }
};