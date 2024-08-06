// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/?envType=study-plan-v2&envId=top-interview-150
// best = my = O(n) O(1)

class Solution {
public:
    int maxProfit(vector<int>& a) {
        long long int profit =0 ;
        int n = a.size() ;
        int buy_val=a[0]  ;
        for(int e=0 ;e<n ;e++){
            if(buy_val<=a[e]) profit+= (a[e] - buy_val) ;
            buy_val = a[e] ;
        }
        return profit ;
    }
};