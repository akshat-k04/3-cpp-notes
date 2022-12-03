//Q.given a number , return all possible permutations. you can return the answer in any order

 #include <bits/stdc++.h>
using namespace std ;

vector<vector<int>> valid ;
void generate( vector<int> &a, int k ){
    for(int e=k ; e<a.size(); e++){

        swap(a[k],a[e]);
        if(k== a.size()-1){
            valid.push_back(a) ;
        }
        generate(a,k+1);
        swap(a[k],a[e]);
    }
}

int main(){
    int n ;
    cin>>n ;
    vector<int> a(n) ;
    for(int e= 1; e<= n ;e++){
        a[e-1]= e ;
    }
    int k =0 ;
    generate(a,k);
    for(int w=0; w<valid.size();w++){
        for(int e=0 ; e<valid[w].size(); e++){
            cout<<valid[w][e]<<" ";
        }
        cout<<endl ;
    }
    
    }