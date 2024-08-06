// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/1298696850/?envType=study-plan-v2&envId=top-interview-150
// my = best = n,1
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size() ;
        int st =0 ; int back = n-1 ;

        while(numbers[st]+numbers[back]!=target){
            if(numbers[st]+numbers[back]>target)back-- ;
            else st++ ;
        }
        vector<int> ans ;
        ans.push_back(st+1) ;
        ans.push_back(back+1) ;
        return ans ;
    }
};