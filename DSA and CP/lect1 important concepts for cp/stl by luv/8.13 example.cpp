 #include <bits/stdc++.h>
using namespace std ;
int main(){
    map<pair<string, string> ,vector<int>> information ;
    cout<<"enter the number of participant you want to enter the info"<<endl ;
    int n ;
    cin>>n ;
    for(int e=0 ;e<n ;e++){
        string name , surname ;
        cout<<"enter name and then surname"<<endl ;
        cin>> name >> surname ;
        cout<<"enter the salary of last 12 months"<<endl ;
        for(int w=0 ; w<12;w++){
            int h ;
            cin>>h ;
            information[{name,surname}].push_back(h);
        }
    }
    for(auto in:information){
        cout<<in.second[3]<<endl ;
    }
}