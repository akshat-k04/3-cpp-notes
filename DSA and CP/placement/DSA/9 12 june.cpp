// https://leetcode.com/problems/jump-game/?envType=study-plan-v2&envId=top-interview-150
//  my =best = O(n) O(1) 

class Solution {
public:
    bool canJump(vector<int>& a) {
        int n = a.size() ;
        int last_true = n-1 ;
        for(int e=n-2 ;e>=0 ;e--){
            if(e+a[e]>=last_true)last_true = e ;
        }
        return last_true==0 ;
    }
};
