// Q. write all the sub sets
 #include <bits/stdc++.h>
using namespace std ;

vector<vector<int>> valid ;
void generate(vector<int> &a,int k,vector<int> &temp){
    for(int e=k ; e< a.size(); e++){
        temp.push_back(a[e]);
        valid.push_back(temp);
        generate(a,e+1,temp);
        temp.pop_back();
    }
}


int main(){
    int n ;
    cin>>n ;
    vector<int> a(n) ;
    for(int e=0 ; e<n ;e++){
        cin>> a[e];
    }
    int k=0 ;
    vector<int> temp ;
    generate(a,k,temp);


// printing
    for(int e=0 ;e<valid.size() ;e++){
        for(int w=0;  w<valid[e].size();w++){
            cout<<valid[e][w]<<" ";
        }
        cout<<endl ;
    }
}