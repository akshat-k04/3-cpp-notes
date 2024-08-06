// https://leetcode.com/problems/container-with-most-water/?envType=study-plan-v2&envId=top-interview-150
// /my = best = n,1

class Solution {
public:
    long long int max(long long int a , long long int b){
        return (a<b)?b:a ;
    }
    int maxArea(vector<int>& height) {
        int n = height.size() ;
        int ini =0 , end = n-1 ;

        long long int ans=0 , temp =0 ;
        temp = (n-1)*(min(height[ini],height[end])) ;
        ans = temp ;

        while(end-ini>=1){
            if(height[ini]>height[end])end-- ;
            else ini++ ;
            temp = (end-ini)*(min(height[ini],height[end])) ;
            ans = max(ans , temp) ;
        }
        return  ans ;
    }
};