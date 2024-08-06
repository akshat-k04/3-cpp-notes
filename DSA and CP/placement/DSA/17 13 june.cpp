// https://leetcode.com/problems/roman-to-integer/?envType=study-plan-v2&envId=top-interview-150
// faltu question

class Solution {
public:
    int romanToInt(string s) {
        int ans =0 ;
        int n = s.size() ;
        map<char,int> mp ; mp['I'] = 1 ;mp['V'] = 5 ;mp['X'] = 10 ;mp['L'] = 50 ;mp['C'] = 100 ;mp['D'] = 500 ;mp['M'] = 1000 ;

        for(int e=1 ;e<n ;e++){
            if(mp[s[e-1]]<mp[s[e]]){
            // cout<<mp[s[e-1]]<< " " ;

                ans-= mp[s[e-1]] ;
            }
            else{
                ans+=mp[s[e-1]] ;
            }
        }
        ans+=mp[s[n-1]] ;
        return ans ;
    }
};