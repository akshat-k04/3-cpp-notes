//eg 3:- 1+1+1,1+2 ,3+0 ;

 #include <bits/stdc++.h>
using namespace std ;

void generate(int &t,vector<vector<int>> &valid , vector<int> &temp ,int high ){
    for(int e=1 ; e<=t ;e++){
        temp.push_back(e) ;
        t-=e ;
        generate(t ,valid ,temp , high ) ;
        t+=e;
        int var =0 ;
        for(int e=0 ; e<temp.size() ; e++){
            var +=temp[e] ;
        }
        if(var==high){
            valid.push_back(temp) ;
            
        }
        //cout<<e ;

        temp.pop_back() ;
    }
}


int main(){
    int t ;
    cin>> t; 
    vector<vector<int>> valid ;
    vector<int> temp ;
    generate(t,valid,temp,t) ;
    for(int e=0;e<valid.size(); e++){
        for(int w=0 ; w<valid[e].size();w++){
            cout<<valid[e][w]<<" "; 
        }
        cout<<endl ;
    }
}