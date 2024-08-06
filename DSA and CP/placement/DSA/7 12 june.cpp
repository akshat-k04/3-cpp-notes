// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/1286306290/?envType=study-plan-v2&envId=top-interview-150
// best = my = O(n) O(1)
class Solution {
public:
    int maxProfit(vector<int>& a) {
        int profit =0 ;
        int n = a.size() ;
        int sell = a[n-1] ;
        for(int e= n-2 ;e>=0 ;e--){
            if(a[e]>sell)sell = a[e] ;
            else profit = max(profit,sell-a[e]) ;
        }
        return profit ;
    }
};