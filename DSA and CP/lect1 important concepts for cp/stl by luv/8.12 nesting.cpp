 #include <bits/stdc++.h>
using namespace std ;
int main(){
    map<pair<string,string> , int> info ;
    string name, surname ;
    int age ;
    cin>> name>> surname>> age ;
    info[{name,surname}]=age ;
    auto it = info.begin();
    cout<<(*it).second<<endl;
    cout<<(*it).first.first<<endl ;
    cout<<(*it).first.second<<endl ;
    

}