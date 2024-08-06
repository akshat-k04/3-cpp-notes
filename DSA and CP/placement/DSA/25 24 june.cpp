// https://leetcode.com/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150
// my = n,n , best = n,1 (can be easily done) 

class Solution {
public:
    bool isPalindrome(string s) {
        vector<int> a ;
        for(int e=0 ;e<s.size() ;e++){
            int h = s[e] ;
            if(h>=65 && h<91)h+=32 ;
            if((h>=97 && h<123)|| (h>=48 && h<=57))a.push_back(h) ;
        }
        bool ans=true ;
        for(int e=0 ;e<a.size() ;e++)if(a[e]!= a[a.size()-1-e])ans = false ;
        return ans ;
    }
};