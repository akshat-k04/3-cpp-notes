// Implement pow(x, n) % d.
// In other words, given x, n and d,
// Find (xn % d)
// Note that remainders on division cannot be negative. In other words, make sure the answer you return is non-negative integer.


// Problem Constraints
// -109 <= x <= 109
// 0 <= n <= 109
// 1 <= d <= 109


// Example Input
// Input 1:
// x = 2
// n = 3
// d = 3
// Input 2:
// x = 5
// n = 2
// d = 6


// Example Output
// Output 1:
// 2
// Output 2:
// 1


// Example Explanation
// Explanation 1:
// 23 % 3 = 8 % 3 = 2.
// Explanation 2:
// 52 % 6 = 25 % 6 = 1.

 #include <bits/stdc++.h>
using namespace std ;
int main(){
    int n,x, d ;
    cin>>x>> n>>d ; // n is power
    vector<int> a ;
    if(x<0){
        x = abs(x)%d ;
        x = d- x ;
    }
    long long int ans =1 ;
    int p=1 ;
    a.push_back(x%d) ;

    while(p<n){
        
            a.push_back((a[a.size()-1]*a[a.size()-1])%d) ;
        
        p*=2 ;
    }
    if(p==n){
        ans = a[a.size()-1] ;
    }
    else if(x==0){
        cout<<0<<endl ;
    }
    else if(n==0){
        cout<<1<<endl ;
    }
    else {
        a.pop_back() ;
        ans = a[a.size()-1] ;
        
        int lst = a.size()-1 ;
        
        p/=2 ;
        int t = p ;
        while(p<n){
            lst-=1 ;
            t/=2 ;
            
            if(p+t<=n && t!=0){
                p+=t ;
                a[lst]%=d ;ans%=d ;
                ans*=a[lst] ;
                ans%=d ;
                cout<< ans<<endl ;
                
            }
        }
    }
    cout<<ans<<endl ;
}