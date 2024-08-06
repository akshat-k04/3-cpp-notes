https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/?envType=study-plan-v2&envId=top-interview-150
// problem in e<=n-m
// my = O(nrootn) O(1) 

class Solution {
public:
    int strStr(string a, string b) {
        int n = a.size() , m = b.size() ;
        for(int e=0 ;e<=n-m ;e++){
            bool check = true ;
            for(int f=0 ;f<m ;f++){
                if(a[e+f]!=b[f]){
                    cout<<e<<" "<<f<<endl ;
                    check=false ;
                    break ;
                }
            }
            if(check)return e ;
        }
        return -1 ;
    }
};