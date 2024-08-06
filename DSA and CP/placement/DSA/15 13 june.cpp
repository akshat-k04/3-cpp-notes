// https://leetcode.com/problems/candy/?envType=study-plan-v2&envId=top-interview-150
// my  O(n) O(n) 
// best O(n) O(1)

class Solution {
public:
    int candy(vector<int>& a) {
        int n = a.size() ;
        vector<int> cnd(n,1) ;
        for(int e=1 ;e<n ;e++){
            if(a[e]>a[e-1])cnd[e]= cnd[e-1]+1 ;
        }
        int ans=cnd[n-1];
        // for(auto v: cnd)cout<<v<<" ";cout<<endl ;

        for(int e=n-2 ;e>=0 ;e--){
            if(a[e]>a[e+1])cnd[e] =max(cnd[e],cnd[e+1]+1) ;
            ans+= cnd[e] ;
        }
        // for(auto v: cnd)cout<<v<<" ";cout<<endl ;
        return ans ;
    }
};