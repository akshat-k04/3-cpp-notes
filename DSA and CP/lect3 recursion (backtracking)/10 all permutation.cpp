//Q.given a number , return all possible permutations. you can return the answer in any order





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

const ll largestLL= 1e18;
const int largestI = 1e9;
const ll primeInt2 = 1000000007;
const int primeInt = 998244353;


//solution here 
vector<vii> ans ;

bool valid( vii &doner,int r){
    bool flag = true ;
    for(int e=0 ;e<doner.size() ; e++){
        if(doner[e]==r){
            flag = false ;
        }
    }
    return flag ;
}

void generate(vii &a , vii &temp,vii & doner){
    if(temp.size()==a.size()){
        ans.pb(temp) ;
        return ;
    }
    for(int e=0 ; e<a.size(); e++){
        if(valid(doner,e)){
            temp.pb(a[e]) ;
            doner.pb(e) ;
            generate(a,temp,doner) ;
            temp.pob() ;
            doner.pob() ;
        }
    }
}

int main(){
    int n ;
    cin>>n ;
    vii a ;
    for(int e=0 ;e<n ;e++){
        int h ;
        cin>>h ;
        a.pb(h) ;
    }
    //input is done
    vii temp ;
    vii lefter  ;
    generate(a,temp,lefter) ;
    for(int e=0 ;e<ans.size() ; e++){
        for(int f=0 ;f<ans[e].size();f++){
            cout<<ans[e][f]<<" ";
        }
        cout<<endl ;
    }
}



















//  #include <bits/stdc++.h>
// using namespace std ;

// vector<vector<int>> valid ;
// void generate( vector<int> &a, int k ){
//     for(int e=k ; e<a.size(); e++){

//         swap(a[k],a[e]);
//         if(k== a.size()-1){
//             valid.push_back(a) ;
//         }
//         generate(a,k+1);
//         swap(a[k],a[e]);
//     }
// }

// int main(){
//     int n ;
//     cin>>n ;
//     vector<int> a(n) ;
//     for(int e= 1; e<= n ;e++){
//         a[e-1]= e ;
//     }
//     int k =0 ;
//     generate(a,k);
//     for(int w=0; w<valid.size();w++){
//         for(int e=0 ; e<valid[w].size(); e++){
//             cout<<valid[w][e]<<" ";
//         }
//         cout<<endl ;
//     }
    
//     }