 #include <bits/stdc++.h>
using namespace std ;
int main(){
    vector<pair<int,string>> v ;// bascically vector<int> int is a data type 
    //in the same way pair is a structure i.e. user defined data type
    
    for(int i=0 ;i<3;i++){
        int x;
        string y ;
        cin>>x;
        cin>>y;
        v.push_back({x,y});// or we ca write v.push_back(make_pair(x,y));
    }
    //this is how we can give input to the vector of item
    for(int i=0 ; i<3 ;i++){
        cout<<v[i].first<<" "<<v[i].second<<endl ;
    }




    //now we will make array of vector 
    vector<int> v[10] ;
    // this means that we  make 10 vector whose size is 0
    // we can take input easily  as we do erlier


    //vector of vector
    vector<vector<int>> ver;
    // v is vector of vectors 
    // lets take input
    int qw;
    cin>> qw ;
    for(int e=0 ; e<qw;e++){
        int dj ;
        cin>>dj ;// we take how many vector we want
        for(int qe=0; qe<dj; qe++){
            int h ;
            cin>>h ;//we just input the size of ver[e] vector
            ver[e].push_back(h);
            // we take a input of vector v[e]
        }
    }
    // now lets push back **a vector**
    vector<int> s;
    ver.push_back(s) ;
}