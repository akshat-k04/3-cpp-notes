// https://leetcode.com/problems/reverse-words-in-a-string/?envType=study-plan-v2&envId=top-interview-150
// my = best  = O(n) O(n) 
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size() ;
        reverse(s.begin() , s.end()) ;
        for(int e=0 ;e<n;e++){
            if(s[e]!=' '){
                int ini = e ;
                while(e<n &&s[e]!=' ')e++ ;
                reverse(s.begin()+ini, s.begin()+e) ;
            }
        }
        string ans ="" ;
        
        for(int e= 0;e<n ;e++){
            if(s[e]==' ' && e==0){}
            else ans+=s[e] ;
            if(s[e]==' '){
                while(e<n && s[e]==' ')e++ ;
                e-- ;
            }
        }
        if(ans[ans.size()-1]==' ')ans.pop_back() ;
        
        return ans;
    }
};