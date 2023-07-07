//https://www.spoj.com/problems/NAKANJ/

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



//Range Queries
 

//print it
void print(vii & a){for(int e=0 ;e<a.size() ;e++){cout<<a[e]<<" " ;}cout<<endl ;}
void printpair(vpii & a){for(int e=0 ;e<a.size() ;e++){cout<<a[e].first<<" "<<a[e].second<<endl ;}cout<<endl ;}

//solution here 

bool isvalid(int x,int y){
    if(x<8 &&x>=0 &&y<8 &&y>=0){
        return true ;
    }
    return false ;
}

void bfs(pair<int,int> par ,vvii &level){
    queue<pair<int,int>> que ;
    level[par.fir][par.sec]=0 ;
    que.push(par) ;
    vpii movements ={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}} ;

    while(que.size()!=0){
        par=que.front() ;
        que.pop() ;
        for(auto move:movements){
            int temx=par.fir+move.fir ;
            int temy =par.sec+move.sec ;
            if(isvalid(temx,temy)){
                if(level[temx][temy]==-1){
                    level[temx][temy]=level[par.fir][par.sec]+1 ;
                    que.push({temx,temy}) ;
                }
            }
        }
    }
}

int main(){
    int t ;
    cin>>t ;
    while(t--){
        string a,b ;
        cin>>a>>b ;
        pair<int,int> ini ;
        ini.fir=(a[0]-'a') ;
        ini.sec=a[1]-'1' ;
        vvii level(8) ;
        for(int e=0 ;e<8 ;e++){
            for(int f=0;f<8;f++){
                level[e].pb(-1) ;
            }
        }
        bfs(ini,level) ;
        cout<<level[b[0]-'a'][b[1]-'1']<<endl ;
    }
}