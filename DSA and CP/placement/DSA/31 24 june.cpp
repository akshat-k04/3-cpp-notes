// https://leetcode.com/problems/longest-substring-without-repeating-characters/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp ;
        int ans =0 ;
        int base =1 ;
        for(int e=0 ;e<s.size() ;e++){
            if(mp[s[e]]!=0){
                int f = base -1 ;
                base = mp[s[e]]+1 ;
                for( ; f<mp[s[e]];f++){
                    mp[s[f]] =0 ;
                }
            }
            mp[s[e]] = e+1 ;
            ans = max(e+1-base+1,ans) ;
        }
        return ans ;
    }
};