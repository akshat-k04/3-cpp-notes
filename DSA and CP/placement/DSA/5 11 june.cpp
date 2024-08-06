// best time (n) space(1)
// my time (n) space(1)
// https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150

// problem is to change the negative value to positive I use 2e9 which makes a clash for 1e9 and -1e9
class Solution {
public:
    int majorityElement(vector<int>& a) {
        vector<int> binary(32) ;
        for(int e=0 ;e<a.size() ;e++){
            if(a[e]<0)a[e] = 2e9+1+a[e] ;
        }
        for(int e=0 ;e<a.size() ;e++){
            int i =0 ;
            while(a[e]!=0){
                if(a[e]%2)binary[i]++ ;
                a[e]/=2 ; i++;
            }
        }
        int ans =0 ,temp=1;
        for(int e=0 ;e<31 ;e++){
            if(e!=0)temp*= 2 ;
            if(binary[e]>int(a.size()/2))ans+= temp ;
        }
        if(ans>1e9)ans-=(2e9+1) ;
        return ans ;
    }
};