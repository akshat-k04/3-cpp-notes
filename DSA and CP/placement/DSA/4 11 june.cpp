// best time (n) space(1)
// my time (nlogn) space (1) --> best achived
// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size() ;
        int ans =n ;
        int num = a[0] ,counter =0;
        for(int e=0 ;e<n ;e++){
            if(a[e]==num)counter++ ;
            else{
                if(counter>=2)counter-= 2 ;
                else counter =0 ;
                ans-= counter ;
                counter= 1;
                num = a[e] ;
            }
            if(counter>2)a[e] = 1e9 ;
        }
        if(counter>=2)counter-= 2 ;
        else counter =0 ;
        ans-= counter ;
        sort(a.begin() ,a.end()) ;
        return ans ;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size() ; // 6
        int ans =n ; // 6
        int i =0 ; //0
        for(int e= 0;e<n ;){ //0
            int j = e ; //0
            e++ ; //1
            while(e<n && a[j]==a[e])e++ ; //3
            e-- ; //2
            if(e-j+1>=2){
                ans-=(e-j-1) ; // 5
                a[i] = a[j] ; i++ ; //1
                a[i] = a[j] ; i++ ; // 2
            }
            else {
                a[i] = a[j] ; i++ ;
            }
            e++ ;
        }
        return ans ;
    }
};