// https://leetcode.com/problems/jump-game-ii/?envType=study-plan-v2&envId=top-interview-150
// my = best O(n) O(1)

class Solution {
public:
    int jump(vector<int>& a) {
        int n = a.size() ;
        int max_jump = -1,max_jump_index = 0 ;
        int life = a[0] ;
        int counter =0; 
        for(int e=1 ;e<n ;e++){
            if(a[e]>max_jump-(e-max_jump_index))max_jump = a[e] , max_jump_index =e ;
            if(life==e){
                life= (max_jump+max_jump_index) ;
                counter++ ;
            }
            else if(e==n-1)counter++ ;
        }
        return counter ;
    }
};