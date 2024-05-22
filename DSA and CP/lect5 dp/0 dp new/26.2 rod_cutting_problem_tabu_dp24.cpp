#include <bits/stdc++.h>
using namespace std ;

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int> dp(n+1) ;
	dp[1]=price[0] ;
	for(int length=2 ;length<=n ;length++){
		dp[length]=price[length-1] ;
		for(int sublength=1;sublength<length;sublength++){
			dp[length]=max(dp[length],dp[sublength]+dp[length-sublength]) ;
		}
	}
	return dp[n] ;
}

int main(){
    int n ;
    cin>>n ;
    for(int e=0 ;e<n ;e++){
        int k ;
        cin>>k ;

        vector<int> a(k) ;
        for(int e=0 ;e<k ;e++)cin>>a[e] ;
        cout<<cutRod(a,k) <<endl ;
    }
}