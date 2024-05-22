#include <bits/stdc++.h>
using namespace std ;


string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.

// previous question code
	vector<vector<int>>	dp(n+1, vector<int> (m+1)) ;

	for(int e=0 ;e<n ;e++){
		for(int f=0 ;f<m ;f++){
			if(s1[e]==s2[f]) dp[e+1][f+1]=1+dp[e][f] ;
			else dp[e+1][f+1]= max(dp[e][f+1],dp[e+1][f]) ;
		}
	}


//creating the string 
	string ans="" ;

	int e=n,f=m ;
	while(e!=0 && f!=0){
		if(s1[e-1]==s2[f-1]){
			ans+=s1[e-1] ;
			e--,f-- ;
		}
		else{
			if(dp[e-1][f]>dp[e][f-1])e-- ;
			else f-- ;
		}
	}
	reverse(ans.begin(),ans.end()) ;
	return ans ;
}

int main(){
    string s1,s2 ;
    cin>>s1>>s2 ;
    cout<<findLCS(s1.size() ,s2.size() , s1,s2) ;
}