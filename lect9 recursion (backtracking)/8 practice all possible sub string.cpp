/* 
a b c d 
a b cd 
a bc d 
a bcd 
ab c d 
ab cd 
abc d 
abcd
*/


//  #include <bits/stdc++.h>
// using namespace std ;

// void generate(int &t,vector<vector<int>> &valid , vector<int> &temp ,int high ){
//     for(int e=1 ; e<=t ;e++){
//         temp.push_back(e) ;
//         t-=e ;
//         generate(t ,valid ,temp , high ) ;
//         t+=e;
//         int var =0 ;
//         for(int e=0 ; e<temp.size() ; e++){
//             var +=temp[e] ;
//         }
//         if(var==high){
//             valid.push_back(temp) ;
            
//         }
//         //cout<<e ;

//         temp.pop_back() ;
//     }
// }

// void maker( vector<vector<string>> &stringValid, string &s , vector<vector<int>> &valid ){
//     int g=valid.size() ;
//     for(int e=0 ; e<g;e++){
//         vector<string> temper ;
//         string fg ;
//         int counter =0 ;
//         int indx =0 ;
//         for(int p=0 ; p<valid[e].size() ; p++){ // take 1 array means 
//             while(counter<valid[e][p]){
//                 fg+= s[indx] ;
//                 indx++;
//                 counter++ ;
//             }
            
//                 counter =0 ;
//                 temper.push_back(fg) ;
//                 fg = "" ;
            
//         }
//         stringValid.push_back(temper);
//     }
// }
// int main(){
//     string s ;
//     cin>> s ;
//     int t ;
//     t = s.size() ; 
//     vector<vector<int>> valid ;
//     vector<int> temp ;
//     generate(t,valid,temp,t) ;


    

//     // now lets make the vector of vector of string ;
//     vector<vector<string>> stringValid ;
//     maker(stringValid,s,valid);
//     for(int e=0;e<stringValid.size(); e++){
//         for(int w=0 ; w<stringValid[e].size();w++){
//             cout<<stringValid[e][w]<<" "; 
//         }
//         cout<<endl ;
//     }
// }

// this is not a good appoch 

 #include <bits/stdc++.h>
using namespace std ;

void generate(vector<vector<string>>  &valid, string &s , vector<string> &temp,int f,int h ){
    //cout<<1 ;
    for(int e=1 ; e<=s.size()-h; e++){
        string d ;
        for(int w=f ; w<e+f ; w++){
            d+=s[w] ;
        }
        temp.push_back(d) ;
        generate(valid , s ,temp , e+f,e+h);
        if(e+f==s.size()){
            valid.push_back(temp) ;
            
        }
        temp.pop_back() ;
    }
}

int main(){
    string s ;
    cin>> s ;
    //cout<<1 ;
    vector<vector<string>>  valid; 
    vector<string> temp ;
    int f=0;
    int h =0 ;
    generate(valid , s , temp, f,h);

    for(int e=0 ; e<valid.size(); e++){
        for(int w=0 ; w<valid[e].size() ; w++){
            cout<< valid[e][w]<<" " ;
        }
        cout<< endl ;
    }
}