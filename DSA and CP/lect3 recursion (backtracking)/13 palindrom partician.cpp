/*
Given a string s, partition s such that every string of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",

Return

  [
    ["a","a","b"]
    ["aa","b"],
  ]
Ordering the results in the answer :

Entry i will come before Entry j if :

len(Entryi[0]) < len(Entryj[0]) OR
(len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR
*
*
*
(len(Entryi[0]) == len(Entryj[0]) AND … len(Entryi[k] < len(Entryj[k]))
In the given example,

   ["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa")


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

// bool checkString(string &stri){
//     for(int i = stri.length() - 1 , e= 0; i >= 0 && e<stri.length(); i-- && e++){
//         if(stri[e]!=stri[i]){
//             return false ;
//         }
//     }
//     return true ;
    

// }

// void seperator(vector<vector<string>> &tp){
//     for(int e=0 ; e<tp.size(); e++){
//     //cout<<1 ;

//         for(int w=0 ; w<tp[e].size() ; w++){
//             bool d= checkString(tp[e][w]) ;
//             //cout<<d<<" "<<tp[e][w] ;
//             if(!d){
//                 auto it =tp.begin()+e ;
//                 tp.erase(it) ;
//                 e-- ;
//                 break ;
//             }
//             // else{
//             //     cout<<tp[e][w]<<" " ;
            
//             // }
//         }
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
//     seperator(stringValid) ;

//     for(int e=0;e<stringValid.size(); e++){
//         for(int w=0 ; w<stringValid[e].size();w++){
//             cout<<stringValid[e][w]<<" "; 
//         }
//         cout<<endl ;
//     }
// }

// this is not a good approch 


// here is the good approch

 #include <bits/stdc++.h>
using namespace std ;


bool palindrome(string &str){
  int n = str.size() ;
  for(int e=0, w=n-1 ; e<n && w>=0 ; ){
    if(str[e]!=str[w]){
      return false ;
    }
    e++ ; w--;
  }
  return true ;
}

bool checker ( vector<string> &temp){
  for(int e=0 ; e<temp.size() ; e++){
    if(!palindrome(temp[e])){
      return false ;
    }
  }
  return true ;
}

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
          if(checker(temp)){
            valid.push_back(temp) ;
          }  
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