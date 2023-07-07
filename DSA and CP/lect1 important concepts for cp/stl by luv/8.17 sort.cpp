/*
we can use inbuilt sort()function for array
let we want have array A of n element we want to sort only 2nd element to 7th element so write
sort(a+1,a+7);
if we want to sort full array then
sort(a,a+n);



for vector 
if want to sort full vector
vector<int> vect;
sort(vect.begin(), vect.end());
if i want to sort 2nd element to n-1th element 
sort(vect.begin()+1, vect.end()-1)

time complexity= O(nlog(n))
*/