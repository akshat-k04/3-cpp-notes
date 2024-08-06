// best time:O(n+m) space: O(1)
// my solution space:O(n+m)  time(n+m)
// https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
        vector<int> ans ;
        int i= 0 , j =0 ;
        while(i<m && j<n){
            if(num1[i]>num2[j])ans.push_back(num2[j]) , j++ ;
            else ans.push_back(num1[i]) ,i++ ;
        }
        for(;i<m ;i++)ans.push_back(num1[i]) ;
        for(;j<n ;j++)ans.push_back(num2[j]) ;
        num1 = ans ;
    }
};