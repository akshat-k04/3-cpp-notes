// https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150
// best time O(n) space O(1)
// my time O(n) space O(1)


// jumping approach
class Solution {
public:
    void rotate(vector<int>& a, int k) {
        int n = a.size() ; //7
        int loop_num = __gcd(n,k) ; //1
        for(int loop=0 ; loop<loop_num ; loop++){ //0
            int ini = n-1-loop ; //6
            int store = ini ; //6
            int value = a[store] ; //7
            do {
                int tem = a[(ini+k)%n] ;
                a[(ini+k)%n] = value ;
                value = tem ;
                ini = (ini+k)%n ;
            }
            while(ini!=store) ;
        }
        return ;
    }
};