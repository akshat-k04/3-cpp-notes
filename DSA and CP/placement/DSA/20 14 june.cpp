// https://leetcode.com/problems/longest-common-prefix/?envType=study-plan-v2&envId=top-interview-150
// faltu

class Solution {
public:
int min(int a, int b){return (a>b)?b:a ;}
    string longestCommonPrefix(vector<string>& strs) {
        string ans ="" ;
        int mini =1e9 ;
        for(int e=0 ;e<strs.size() ;e++){
            mini = min(strs[e].size(),mini) ;
        }

        for(int indx =0 ; indx<mini ;indx++){
            bool temp = true ;

            for(int e=0 ;e<strs.size() ;e++){
                if(strs[e][indx]!=strs[0][indx]){temp =false ;break ;}
            }
            if(temp) ans+=strs[0][indx] ;
            else break ;
        }
        return ans ;
    }
};