 #include <bits/stdc++.h>
using namespace std ;
int main(){
    
        int  n; 
        cin>>n ;
        stack<int> series ;
        vector<int> ans(n,-1),index;

        for(int e=0 ; e<n ;e++){
            int h ;
            cin>>h ;
            if(!series.empty()){
                while(!series.empty()){
                    if(h>series.top()){
                        ans[index.back()]=h;
                        index.pop_back();
                        series.pop();
                    }
                    else{
                        break ;
                    }
                }
                series.push(h);
                index.push_back(e);
            }
            else{
                series.push(h);
                index.push_back(e);
            }
        }
        for(int e=0 ; e<n;e++){
            cout<<ans[e]<<" ";
        }
        cout<<endl; 
    
}