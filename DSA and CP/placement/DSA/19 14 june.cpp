// https://leetcode.com/problems/length-of-last-word/?envType=study-plan-v2&envId=top-interview-150
// faltu

class Solution {
public:
    int lengthOfLastWord(string s) {
        string ans ="" ;
        int n = s.size() ;
        bool vanish = false ;
        for(int e=0 ;e<n ;e++){
            if(s[e]==' '){vanish=true ;continue ;}
            else {
                if(vanish){
                    ans=s[e] ;
                    vanish=false ;
                }
                else ans+=s[e] ;
            }
        }
        return ans.size() ;
    }
};