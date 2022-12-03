 #include <bits/stdc++.h>
using namespace std ;
int main(){
    int t ;
    cin>>t ;
    for(int r=0; r<t ;r++){
        int n ;
        cin>>n ;
        stack<char> net ;
        for(int e=0; e<n;e++){
            char h ;
            cin>>h;
            if(h=='{'||h=='['||h=='('){
                net.push(h);
            }
            else {
                if((h==']' && net.top()=='[')||(h=='}' && net.top()=='{')||(h==')'  && net.top()=='(')){
                    net.pop();
                }
                else{
                    cout<<"NO"<<endl;
                    goto l;
                }
            }
            
        }
        if(net.empty()){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        l:;
    }
}