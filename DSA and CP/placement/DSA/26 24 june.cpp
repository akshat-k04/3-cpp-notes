//https://leetcode.com/problems/is-subsequence/?envType=study-plan-v2&envId=top-interview-150
// faltu

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ss = s.size() , ts = t.size() ;
        int i = 0, j=0 ;

        while(i<ss && j<ts){
            if(s[i]==t[j])i++ ;
            j++ ;
        }
        return i==ss ;
    }
};