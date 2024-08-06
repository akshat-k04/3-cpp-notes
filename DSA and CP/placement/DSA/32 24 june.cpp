// https://leetcode.com/problems/substring-with-concatenation-of-all-words/?envType=study-plan-v2&envId=top-interview-150

// this solution is good but need to optimize more by removing the logn in time 
#include <bits/stdc++.h>
class Solution {
public:
    int min(int a, int b){return (a>b? b:a) ;}
    vector<int> findSubstring(string s, vector<string>& words) {
        int mapper =1 ;
        map<string, int> temp ;
        for(auto & v :words){if(temp[v]==0){temp[v]= mapper ;mapper++ ;}}

        int len = words[0].size() ;
        vector<vector<int>> list(len) ;
        for(int ini=0 ;ini<min(len,s.size()) ;ini++){
            for(int f= ini ; f+len<=s.size() ; f+=len){
                string str ="" ;
                for(int e=f ; e<f+len ;e++)str+=s[e] ;
                list[ini].push_back(temp[str]) ;
            }
        }       
        vector<int> ans ;
        for(int ini=0 ; ini<len ; ini++){
            multiset<int> req_permutation ;
            for(auto &v:words){
                req_permutation.insert(temp[v]) ;
            }
            multiset<int> extra ;
            if(list[ini].size()<words.size())continue ;
            else{
                int forward = 0 ;
                // cout<<req_permutation.size()<<" "<<extra.size()<<endl ;
                for( ;forward<words.size() ;forward++){
                    if(req_permutation.find(list[ini][forward])!=req_permutation.end())req_permutation.erase(req_permutation.find(list[ini][forward])) ;
                    else extra.insert(list[ini][forward]) ;
                    // cout<<req_permutation.size()<<" "<<extra.size()<<endl ;
                }
                if(req_permutation.size()==0)ans.push_back(ini+forward*len -words.size()*len) ;

                for( ; forward<list[ini].size(); forward++){
                    if(extra.find(list[ini][forward-words.size()])!=extra.end())extra.erase(extra.find(list[ini][forward-words.size()])) ;
                    else req_permutation.insert(list[ini][forward-words.size()]) ;

                    if(req_permutation.find(list[ini][forward])!=req_permutation.end())req_permutation.erase(req_permutation.find(list[ini][forward])) ;
                    else extra.insert(list[ini][forward]) ;

                    if(req_permutation.size()==0){
                        ans.push_back(ini+forward*len+len -words.size()*len) ; 
                        
                    } 
                    // cout<<req_permutation.size()<<" "<<extra.size()<<endl ;
                }
            }
        }
        return ans ;
    }
};