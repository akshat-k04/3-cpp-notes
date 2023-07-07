/*
5,(1/5) are multiplicative inverse 
5 ,-5 are additive inverse

a,b are modulo multiplicative inverse of each other if (a*b)%d==1 

*/



/*
1. we have 2 methods to calculate the inverse 
   which we study in next 2 files

2. use of multiplicative inverse 
   if we want to find this (a/b)%m then we can weite it as (a*c)%m  where b,c are modulo inverse of each other
   but we have some conditions 
   a. b,m must be co-prime then only  the modular inverse exist 
   b. a%bmust equals to 0


   proof of this :-


   let a = k*b 
   (a/b)%m = (kb/b)%m = k%m 

   let c be the modulo multiplicative inverse of b 

   (b*k *c)%m = ((b*c%m)*(k%m))%m = (1*k%m)%m= k%m 

hence proved


*/