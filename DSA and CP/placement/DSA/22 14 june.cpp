// https://leetcode.com/problems/zigzag-conversion/?envType=study-plan-v2&envId=top-interview-150
// my = O(n) O(n) =best

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s ;
        int n = s.size() ;
        int row =1 ;

        string ans ="" ;
        for(row = 1; row<=numRows ;row++){
            for(int e= row-1 ;e<n ;e+=(numRows*2-2)){
                ans+=s[e] ; 
                if(row!= 1 && row!= numRows &&e+numRows*2-2*(row)<n){
                    ans+=s[e+numRows*2-2*(row)] ;
                }
            }
        }
        return ans ;
    }
};