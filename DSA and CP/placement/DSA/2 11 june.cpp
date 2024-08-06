// best time O(n) space O(1) 
// my time O(nogn) space O(1)
// https://leetcode.com/problems/remove-element/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lrg = 1e9 ;
        int ans = nums.size() ;
        for(int e=0 ;e<nums.size() ;e++)if(nums[e]==val)nums[e]=lrg , ans-- ;
        sort(nums.begin() , nums.end()) ;
        return ans ;
    }
};