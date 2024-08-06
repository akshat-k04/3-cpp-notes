// https://leetcode.com/problems/integer-to-roman/?envType=study-plan-v2&envId=top-interview-150
// faltu question

class Solution {
public:
    string intToRoman(int num) {
        int once = num%10 ; num/=10 ;
        int tence = num%10 ; num/= 10 ;
        int hundreds = num%10 ; num/= 10 ;
        int thousands = num%10 ;

        string s ="" ;

        while(thousands)s+='M', thousands-- ;
        if(hundreds==9){
            s+="CM" ;
        }
        else if(hundreds==4){
            s+="CD" ;
        }
        else{
            if(hundreds>=5)s+='D', hundreds-=5;
            while(hundreds)s+="C" , hundreds-- ;
        }


        if(tence==9){
            s+="XC" ;
        }
        else if(tence==4){
            s+="XL" ;
        }
        else{
            if(tence>=5)s+='L', tence-=5;
            while(tence)s+="X" , tence-- ;
        }


        if(once==9){
            s+="IX" ;
        }
        else if(once==4){
            s+="IV" ;
        }
        else{
            if(once>=5)s+='V', once-=5;
            while(once)s+="I" , once-- ;
        }
        
        return s ;
    }
};