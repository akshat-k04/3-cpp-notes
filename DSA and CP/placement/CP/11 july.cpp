#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define pob pop_back
#define fir first 
#define sec second
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vii;
typedef vector<vector<int>> vvii;

void print(vii& a){int n = a.size() ;for(int e=0 ;e<n ;e++)cout<<a[e] <<' ';cout<<endl ;}

void take_vec(vii&a , int n){for(int e=0 ;e<n ;e++){int h ; cin>>h ; a.push_back(h) ;}}


void create_group(vector<string> &a, int r, int c,vector<vector<int>> & group , int num){
    group[r][c] =num ;
    int n = a.size() , m = a[0].size() ;
    vector<pair<int,int>> move = {{-1,0},{+1,0}, {0,-1}, {0,+1}} ;

    for(auto v: move){
        if(r+v.fir< n && r+v.fir>=0 && c+v.sec>=0 && c+v.sec<m && a[r+v.fir][c+v.sec]=='#' && group[r+v.fir][c+v.sec]==0){
            create_group(a,r+v.fir , c+v.sec , group , num) ;
        }
    }
}
void solve(){
    int n ,m ;
    cin>>n>>m ;
    vector<string> a(n) ;
    for(int e=0 ;e<n ;e++)cin>>a[e] ;

    //  input is done 

    //  first create the groups 
    vector<vector<int>> group(n, vector<int> (m)) ;
    int no = 0 ;
    for(int e=0 ;e<n ;e++){
        for(int f=0 ;f<m ;f++){
            if(a[e][f]=='#' && group[e][f]==0){
                no++ ;
                create_group(a,e,f,group,no) ;
            }
        }
    }

    //  now find the size of groups 
    vector<int> group_size(no+1) ;

    for(int e=0 ;e<n ;e++){
        for(int f=0 ;f<m ;f++){
            group_size[group[e][f]]++ ;
        }
    }
    group_size[0] =0 ;
    
    // now I will check if doing operation will help or not 

    vii ans_col(m) ;
    for(int col =0 ; col<m ; col++){
        set<int> list ;
        for(int row=0 ; row<n ;row++){
            list.insert(group[row][col]) ;
            if(col+1<m)list.insert(group[row][col+1]) ;
            if(col-1>=0)list.insert(group[row][col-1]) ;
        }
        for(auto v: list)ans_col[col]+= group_size[v] ;
        for(int row=0 ; row<n ; row++) if(a[row][col]=='.')ans_col[col]++ ;
    }

    vii ans_row(n) ;
    for(int row =0 ; row<n ; row++){
        set<int> list ;
        for(int col=0 ; col<m ;col++){
            list.insert(group[row][col]) ;
            if(row+1<n)list.insert(group[row+1][col]) ;
            if(row-1>=0)list.insert(group[row-1][col]) ;
        }
        for(auto v: list)ans_row[row]+= group_size[v] ;
        for(int col=0 ; col<m ; col++) if(a[row][col]=='.')ans_row[row]++ ;
    }

    int maxer =0 ;
    for(auto v: ans_col)maxer = max(maxer, v) ;
    for(auto v: ans_row)maxer = max(maxer, v) ;
    // print(ans_col) ;
    // print(ans_row) ;
    // for(auto v: group){
    //     print(v) ;
    // }
    // cout<<endl ;

    // print(group_size) ;
    cout<<maxer<<endl ;
}

int main(){
    int t ;
    cin>>t ;
    for(int e=0 ;e<t ;e++){
        solve() ;
    }
}