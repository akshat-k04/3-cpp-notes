// https://leetcode.com/problems/h-index/?envType=study-plan-v2&envId=top-interview-150
// my = best  = O(nlogn)  O(1) 
class Solution {
public:
    int hIndex(vector<int>& a) {
        int n = a.size() ;
        sort(a.begin() , a.end()) ;

        int ini =0 , end = 1000, mid ;
        while(end-ini>1){
            mid = (ini+end)/2 ;
            // check for mid 
            int index = lower_bound(a.begin() ,a.end() , mid) -a.begin() ;
            int num = n-index ;
            if(num>=mid)ini = mid ;
            else end = mid ;
        }
        return ini ;
    }
};