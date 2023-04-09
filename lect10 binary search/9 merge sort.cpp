//done
//sorting the array (mergee sort)

 #include <bits/stdc++.h>
using namespace std ;
vector<int> a ;
void murder(int l , int r , int mid){
    queue<int > left , right , total ;
    for(int e=l ; e<=mid ;e++){
        left.push(a[e]) ;
    }
    for(int e=mid+1 ; e<=r ; e++){
        right.push(a[e]) ;
    }
    for(int e=l ; e<=r ;e++){
        if(left.size()==0){
            total.push(right.front()) ;
            right.pop() ;
        }
        else if(right.size()==0){
            total.push(left.front()) ;
            left.pop() ;
        }
        else if(left.front()>right.front()){
            total.push(right.front()) ;
            right.pop() ;
        }
        else {
            total.push(left.front()) ;
            left.pop() ;
        }
    }
    for(int e=l ; e<=r ;e++){
        a[e]=total.front() ;
        total.pop() ;
    }
}
void sorting(int l, int r, int mid){
    if(r-l>1){
        sorting(l,mid,(l+mid)/2) ;
        sorting(mid+1 ,r , (mid+1+r)/2) ;    
    }
    // cout<<l<<" "<<r<<" "<<endl ;
    murder(l,r,mid) ;
    
}

int main(){
    int t ;
    cin>>t ;
    
    for(int r=0 ;r<t;r++){
        int h ;
        cin>>h ;
        a.push_back(h) ;
    }
    sorting(0,t-1 , (t-1)/2) ;
    for(int e=0  ;e<t ;e++){
        cout<<a[e]<<" " ;
    }
}