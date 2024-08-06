//https://leetcode.com/problems/3sum/?envType=study-plan-v2&envId=top-interview-150
// my = best  = n^2 , n

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size() ;
        int one , two  , three;
        vector<vector<int>> ans ;
        sort(a.begin() ,a.end()) ;

        for(one=0 ; one<n; one++){
            if(one!=0 && a[one]==a[one-1])continue ;
            two = one+1 , three = n-1 ;
            while(three-two>0){
                if(a[one]+a[two]+a[three]==0 && (ans.size()==0 || ans[ans.size()-1][0]!=a[one] ||ans[ans.size()-1][1]!=a[two])){
                    vector<int> temp={a[one],a[two],a[three]} ;
                    ans.push_back(temp) ;
                }
                if(a[one]+a[two]+a[three]>0)three--;
                else two++ ;
            }  
        }
        return ans ;
    }
};