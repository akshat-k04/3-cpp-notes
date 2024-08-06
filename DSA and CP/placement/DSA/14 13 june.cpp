// https://leetcode.com/problems/gas-station/?envType=study-plan-v2&envId=top-interview-150
// my = best = O(n) O(1) 

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size() ;
        for(int e=0 ;e<n ; e++){
            gas[e] -= cost[(e)%n] ;
        }
        //  this is the net gas at the perticular station

        int fuel =0 ;
        int ini =0 ;
        for(int e=0 ;e<n ;e++){
            fuel+= gas[e] ;
            if(fuel<0){
                ini = e+1 ;
                fuel =0 ;
            }
        }
        if(ini==n)return -1 ;
        else{
            fuel =0 ;
            for(int e=0 ;e<n ;e++){
                fuel += gas[(ini+e)%n] ;
                if(fuel<0)return -1 ;
            }
            return ini ;
        }
    }
};