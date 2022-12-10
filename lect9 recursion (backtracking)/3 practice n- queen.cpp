 #include <bits/stdc++.h>
using namespace std ;

bool validate(vector<vector<char>> &temp , int e ){
    for(int w=0 ; w<temp.size() ;w++){
        for(int d=0 ; d<temp[w].size() ;d++){
            if(temp[w][d]=='Q'){
                if(e==d){
                    return false ;
                }
                else if(temp.size()-w == e-d ||temp.size()-w == d-e){
                    return false ;
                }
            }
        }
    }
    return true ;
}

void generate (vector<vector<vector<char>>> &valid , vector<vector<char>> &temp, int n,int pr ){
    if(pr<=n){
    vector<char>s ;
    for(int e=0 ;e<n ; e++){
        for(int w=0 ;w<n ; w++){
            if(e==w){
                s.push_back('Q') ;
            }
            else{
                s.push_back('.') ;
            }
        }
        if(validate(temp , e)){
            temp.push_back(s);
        }
        else{
            s.clear() ;
            continue ;
        }
        
        generate(valid,temp,n ,pr+1);
        if(pr==n){
            valid.push_back(temp) ;
        }
        temp.pop_back() ;
        s.clear() ;
    }
    }
}

int main(){
    int n ;
    cin>> n ;
    vector<vector<vector<char>>> valid ;
    vector<vector<char>> temp ;
    int pr =1 ;
    generate(valid,temp,n,pr) ;
    for(int e=0 ; e<valid.size();e++){
        for(int w=0 ; w<valid[e].size(); w++){
            for(int r=0 ; r<valid[e][w].size(); r++){
                cout<<valid[e][w][r]<<" " ;
            }
            cout<< endl ;
        }
        cout<< endl ;
    }
}