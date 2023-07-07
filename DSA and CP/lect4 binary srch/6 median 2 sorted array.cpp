//not done


// There are two sorted arrays A and B of size m and n respectively.

// Find the median of the two sorted arrays ( The median of the array formed by merging both arrays ).

// The overall run time complexity should be O(log (m+n)).

// NOTE: If the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element. For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5 


// Problem Constraints
// 0 <= |A| <= 106
// 0 <= |B| <= 106
// 1 <= |A| + |B| <= 2 * 106


// Input Format
// The first argument is an integer array A.
// The second argument is an integer array B.


// Output Format
// Return a double value equal to the median.


// Example Input
// A : [1 4 5]
// B : [2 3]


// Example Output
// 3


// Example Explanation
// Merged A and B will be : [1, 2, 3, 4, 5]
// Its median will be 3


#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define pob pop_back
//#define fir first 
//#define sec second
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vii;
typedef vector<vector<int>> vvii;

const ll largestLL= 1e18;
const int largestI = 1e9;
const ll primeInt2 = 1000000007;
const int primeInt = 998244353;

/*inbuilt functions:-
gcd :- __gcd(a,b)
to convert int to string to_string(number)
to convert char to int we have to handle it mannually int a = '6' - '0' 
queue<int>, stack<int> --> has push() ,pop() , front() for queue ,top() for stack , 
reverse(a.begin() , a.end())
st.erase(st.begin()+index) or st.erase(st.begin()+iniIndex , st.begin() + lstIndex)// note that lst index will not erase it is similar to open bracket 
 upper_bound(a.begin(),a.end(),5):- gives iterator strictly less than the 5
lower_bound(a.begin(),a.end(),5):- greater than or equals to the 5
*/


//solution here 


int main(){
    int n ,m ;
    cin>>n>>m ;
    vii a,b ;
    for(int e=0 ;e<n ;e++){
        int h ;
        cin>>h ;
        a.pb(h); 
    }
    for(int e=0 ;e<m ; e++){
        int h ;
        cin>>h ;
        b.pb(h) ;
    }
    // input is done



    int reqposi = (n+m)/2 ;
    int ini=0 ; int lst =n-1 ;
    int mid=-1 ;
    int indx ;
    while(lst-ini>1){
        mid = (ini+lst)/2 ;
        indx = lower_bound(b.begin() , b.end() , a[mid])- b.begin() ;
        if(mid+indx<reqposi){
            ini=mid ;
        }
        else{
            lst = mid ;
        }
    }
    int resultindx1,resultindx2  ;
    double ans ;
    // cout<<a[lst]<<endl ;
    if(n==0){
        if(m%2==0){
            ans =( b[m/2]+b[m/2 -1])/2.0 ;
        }
        else{
            ans = b[(m-1)/2] ;
        }
    }
    else if(m==0){
        if(n%2==0){
            ans=(a[n/2]+a[n/2 -1])/2.0 ;
        }
        else{
            ans = a[(n-1)/2] ;
        }
    }
    else{
    indx = (lower_bound(b.begin() , b.end() , a[lst])- b.begin()) ;
    // cout<<indx<<endl ;
    if(lst+indx<reqposi){
        
        resultindx1 = reqposi-n ;
        if((n+m)%2==0){
            if(resultindx1==0){
                resultindx2 = n-1 ;
                ans= (a[resultindx2]+b[0])/2.0 ;
            }
            else{
                ans=( b[resultindx1]+b[resultindx1-1] )/2.0;
            }
        }
        else{
            ans = b[resultindx1] ;
        }
    }
    else if(ini +(lower_bound(b.begin() , b.end() , a[ini])- b.begin())>reqposi){
        // indx= (upper_bound(b.begin() , b.end() , a[ini])- b.begin()) ;
        if((m+n)%2==0){
            ans= b[reqposi]+b[reqposi-1] ;
            ans/=2.0 ; 
        }
        else{
            ans = b[reqposi] ;
        }
    }
    else if(lst+indx==reqposi){
        // cout<<1<<endl;
        ans =a[lst] ;
        if((n+m)%2==0){
        if(indx!=0){
            ans+= max(a[lst-1],b[indx-1]) ;
        }
        else {
            ans+= a[lst-1] ;
        }
        
        ans/= 2.0 ;
        }
    }
    else if(ini +(lower_bound(b.begin() , b.end() , a[ini])- b.begin())==reqposi){
        // cout<<1 <<endl ;
        ans= a[ini] ;
        if((n+m)%2==0){
        ans+= min(a[ini+1],b[(lower_bound(b.begin() , b.end() , a[ini])- b.begin())-1]) ;
        ans/=2.0;
        }
    }
    else{
        // cout<<indx<<endl ;
        // int indx1 = (upper_bound(b.begin() , b.end() , a[ini])- b.begin()) ;
        if((m+n)%2==0){
            ans = (b[reqposi-ini-1]+max(b[reqposi-ini-2],a[ini]))/2.0 ;
        }
        else{
            ans = b[reqposi-ini-1] ;
        }
    }
    }
    cout<<ans <<endl ;



}