/*
here we deal with bit of a number
means number in binary form

shift operator:- >> ,<<
eg:- 5>>2 = 1 means remove last 2 bits from 5
     101 is 5 . now removing 2 bit we get 1 (in binary) i.e. 1 in decimal
     5<<2 means add 2 0s in last 
     we get 10100 i.e. 20
*/

bool isPowerOfTwo(unsigned int n) {
    return n && !(n & (n - 1)); // if n!=0 and (n & (n - 1))==0 then it means n is power of 2
}