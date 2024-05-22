// https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284
#include <bits/stdc++.h>
using namespace std ;

int memo(int length , vector<int> &price,vector<int> &dp ){
	if(dp[length]!=-1)return dp[length] ;
	int ans=0 ;
	for(int i=1 ;i<=length ;i++){
		int temp_ans = price[i-1]+memo(length-i,price,dp) ;
		ans=max(ans,temp_ans) ;
	}
	return dp[length]=ans ;
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int> dp(n+1,-1) ;
	return memo(n,price,dp) ;
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