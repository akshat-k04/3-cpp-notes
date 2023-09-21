#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define pob pop_back
#define fir first 
#define sec second
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vii;
typedef vector<vector<int>> vvii;

const ll largestLL= 1e18;
const int largestI = 1e9;
const ll primeInt2 = 1000000007;
const int primeInt = 998244353;

/*inbuilt functions:-

1.gcd :- __gcd(a,b)

2.to convert int to string to_string(number)
3.to convert char to int we have to handle it mannually int a = '6' - '0' 

4.queue<int>, stack<int> --> has push() ,pop() , front() for queue ,top() for stack , 
5.reverse(a.begin() , a.end())
6.st.erase(st.begin()+index) or st.erase(st.begin()+iniIndex , st.begin() + lstIndex)// note that lst index will not erase it is similar to open bracket 
7.upper_bound(a.begin(),a.end(),5):- smallest that is greater then 5
8.lower_bound(a.begin(),a.end(),5):- greater than or equals to the 5
9. if the vector is in decreasing order then we use a.rbegin() , a.rend() 
10.for map and set both, mp.find(key) if present then iterator points there else iterator point on mp.end()
*/

// number theory
//1. check prime
bool isprime(ll n){ // true if n is prime 
    if(n<=1){
        return false ;
    }
    else{
        for(ll e=2 ;e<sqrt(n);e++){
            if(n%e==0){
                return false ;
            } 
        }
        return true ;
    }
}

//2.binary exponentiation
ll binpow(ll a, ll b, ll m) { 
    //b=m-2 ;// if want to find the modular inverse 
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1){
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

//3.prime composite sieve
void primesieve(vii & a){
    // 0 means composite
    // 1 means prime 
    // 1 is not a prime nor composite but here we consider it as composite
    a[0]=0 ;
    a[1]=0 ;
    for(int e=2 ;e<=sqrt(a.size())+1 ;e++){
        if(a[e]==1){
            int f=e*e ;
            while(f<a.size()){
                a[f]=0 ;
                f+=e ;
            }
        }
    }
}

//4. prime factorization sieve and function
void primefactorsieve(vii & sieve){//2 2 5 for 20
    for(ll e=2 ;e<sieve.size();e++){
        if(sieve[e]==0){
            sieve[e]=e ;
            for(ll f=e*e ;f<sieve.size() ;f+=e){
                if(sieve[f]==0){
                    sieve[f]=e ;
                }
            }
        }
    }
}

void allPrimefactors(int num,vii & sieve,vii &ans){
    while(num>1){
        ans.pb(sieve[num]) ;
        num/=sieve[num] ;
    }
}

//5. extended gcd
// a*x+b*y = gcd(a,b) , we find the integral value of x,y using function
// if a,b are co-prime then modular inverse of a = (x%b +b)%b  wrt b 
int extendedgcd(int a, int b, int& x, int& y) { //return value is gcd
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extendedgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

//6. factorial
void createFactorial(vll & factorial){
    factorial[0]=1 ;
    for(int e=1 ;e<factorial.size() ;e++){
        factorial[e] = (factorial[e-1]*e)  % primeInt2;
    }
}

ll combination(ll n,ll r,vll & factorial){
    ll ans = factorial[n] ;
    ll deno = factorial[n-r] * factorial[r] % primeInt2 ;
    ans = (ans* binpow(deno,primeInt2-2 ,primeInt2))  % primeInt2 ;
    return ans ;
}

//7. ETF
void etfsieve(vii &sieve){
    for(int e=0 ;e<sieve.size() ;e++){
        sieve[e]=e ;
    }
    for(int e=2 ; e<sieve.size();e++){
        if(sieve[e]==e){ //means it is prime
            sieve[e] = e-1 ;
            for(int f=2*e ;f<sieve.size();f+=e){
                sieve[f]/=e ;
                sieve[f]*=(e-1) ;
            }
        }
    }
}

//DSU

void make(int v , vii&parent,vii&size){
    parent[v]=v ;
    size[v] =1 ;
}
int find(int v ,vii&parent){// gives the root of the tree
    if(v==parent[v]){
        return v ;
    }
    return find(parent[v],parent) ;
}
void Union(int a,int b,vii&parent,vii&size){
    a=find(a,parent) ;
    b =find(b,parent) ;
    if(a!=b){
        if(size[a]<size[b])swap(a,b) ;
        parent[b]=a ;
        size[a]+=size[b] ;
    }
}

//graph

void dfs(int vertex,vvii & list,vii &parent){ // parent of top ost node is -1 so write it while declearing parent vector ,for rest write -2

    //case 1:- take action on vertex after entering the vertex

    for(auto child: list[vertex]){
        if(parent[child]!=-2)continue ;


        parent[child]=vertex ;

        // case 2:- take action on child before entering the child

        dfs(child,list,parent) ;

        // case 3:- take action on child after exiting the child
    }

    //case 4:- take action on vertex before exiting the vertex
}


void bfs(int vertex,vvii &list,vii &level){
    level[vertex]=0 ;
    queue<int> que ;
    que.push(vertex);

    while(que.size()!=0){
        vertex=que.front() ;
        que.pop() ;
        for(auto child:list[vertex]){
            if(level[child]!=-1)continue ;
            que.push(child) ;
            level[child]=level[vertex]+1 ;
        }
    }
}

// vii dist(n,1000000007) ; write this in main func
// list contain node and weight of edge connecting node and parent node
void dijkstra(int vertex,vector<vpii>&list,vii&dist){
    int n=list.size() ;
    vii visited(n) ;

    set<pair<int,int>> que ; // weight,node

    //inserted the first element from where need to find the mini dist
    que.insert({0,vertex}) ;
    dist[vertex]=0 ;
    while(que.size()!=0){
        vertex = (*que.begin()).sec ;
        int length = (*que.begin()).fir ;//dist till this vertex
        que.erase(que.begin()) ;

        if(visited[vertex]==1)continue ;
        visited[vertex]=1 ;
        
        for(auto child:list[vertex]){
            
            if(length+child.sec<dist[child.fir]){
                dist[child.fir]=length+child.sec ;
                que.insert({dist[child.fir],child.fir}) ;
            }
        }
    }
}


//trees

//1. traversal
/*
preorder(root, left, right)
inorder(left,root,right) 
postorder(left,right,root) 
ex:-
void inoder(struct node*root){
    if(root==NULL)return ;
    inoder(root->left) ;
    cout<<root-> data <<" " ;
    inoder(root->right) ;
}
*/

//2.LCA
//0-indexed 
void fillancester(int root, vvii &list , vvii &ancesters){
    // vvii ancesters ;  (write in main function) 

    //initializing
    int n=list.size() ; // number of node
    int k = log2(n) +1 ;
    vii temp(k,-1) ;
    ancesters.assign(n,temp) ;
    vii parent(n,-2) ;parent[root]=-1 ;
    dfs(root,list,parent) ;

    // finding 2^i th ancester
    for(int e=0 ;e<n ;e++) ancesters[e][0]=parent[e] ;
    for(int e=1 ;e<k ;e++){
        for(int f=0 ;f<n ;f++){
            int prev =ancesters[f][e-1] ;
            if(prev!=-1)ancesters[f][e] =ancesters[prev][e-1] ;
        }
    }
}

int LCA(int root,int a,int b , vvii&ancesters,vvii&list){
    int n = ancesters.size() ;
    
    vii level(n,-1) ; // level means depth
    bfs(root,list,level) ;
    if(level[a]<level[b]){
        swap(a,b) ;
    }
    int diff = level[a]-level[b] ;
    // making a to same level

    while(diff>0){
        int i = log2(diff) ;
        a= ancesters[a][i];
        diff-=binpow(2,i,primeInt2) ;
    }

    if(a==b)return a ;
    int m = ancesters[0].size() ;// =log2(n)+1
    for (int i=m-1;i>=0;i--) {
        if (ancesters[a][i]!=-1 &&ancesters[a][i]!=ancesters[b][i]) {
            a=ancesters[a][i];
            b=ancesters[b][i];
        }
    }
    if (a!=b) return ancesters[a][0];
    else return a;
}


//Range Queries (range update and all this are left)

void built(int indx,int ini,int end ,vii&tree ,vii & a){
    // in main func make  vii tree(4*a.size()) ;
    //then run func as built(1,0,n-1,tree,a);
    if(ini==end)tree[indx]=a[ini] ;
    else{
        int mid =ini+end ;mid/=2 ;
        built(2*indx,ini,mid ,tree,a) ;
        built(2*indx+1,mid+1,end,tree,a) ;

//depends on question
        tree[indx]=tree[2*indx]+tree[2*indx+1] ;
    }
}

int query(int l,int r ,vii&tree,int ini ,int end,int node){
    // call query like this query(l,r,tree,0,n-1,1) ; in main func

    if(l>end||r<ini){
//depends on question
        return  0 ; 
    }
    if(l<=ini && end<=r){
        // the range ini to end completely overlap on query
        return tree[node] ;
    }
    else {
        int mid =(ini+end)/2 ;
//depends on question
        return query(l,r,tree,ini,mid,2*node)+query(l,r,tree,mid+1,end,2*node+1) ;
    }
}

void updateIndx(int ini,int end,int node,vii&tree,int indx,int val,vii&a){
//write this in main func:- updateIndx(0,n-1,1,tree,indx,val);

    if(ini==end){
        tree[node]=val ;
        a[indx]=val ; // just for tp no relation with this code
        return ;
    }
    if(ini<=indx && indx<=end){
        int mid =(ini+end)/2 ;
        updateIndx(ini,mid,2*node,tree,indx,val,a) ;
        updateIndx(mid+1,end,2*node+1,tree,indx,val,a) ;

//depends on question
        tree[node]=tree[2*node]+tree[2*node+1] ; 
    }
    return ;
}

//print it
void print(vii & a){for(int e=0 ;e<a.size() ;e++){cout<<a[e]<<" " ;}cout<<endl ;}
void printpair(vpii & a){for(int e=0 ;e<a.size() ;e++){cout<<a[e].first<<" "<<a[e].second<<endl ;}cout<<endl ;}

//solution here 


int main(){
    int t ;
    cin>>t ;
    for(int r=0 ;r<t ;r++){
        int n ,k ;
        cin>>n>>k ;
        string s ; cin>>s ;
        vii ans ;
        if(s[0]=='1') ans.pb(0) ;
        for(int e=0 ;e<n ;){
            char dic = s[e] ;
            int counter =0 ;
            while(e<n &&s[e]==dic){
                counter++ ; e++ ;
            }
            ans.pb(counter) ;
        }
        if(ans.size()%2==1) ans.pb(0) ;
        vii l0indxL1values(3001,-1) ;
        for(int e=0 ;e<ans.size() ;e+=2){
            int templ0=0 ;
            int buffer = k ;
            for(int f=e ;f<ans.size() ;f+=2){ // we are finding l0 max from e
                templ0+=ans[f] ;
                if(buffer<ans[f+1]){
                    templ0+= buffer ;
                    // now calculate the l1 and put this value to l0indx[temp]
                    int l1 =0 ;
                    for(int g =0 ;g<e ;g++)l1=max(l1,ans[g+1]) ;
                    for(int g = f+2 ;g<ans.size() ;g+=2)l1=max(l1,ans[g+1]) ;
                    l1=max(l1,ans[f+1]-buffer) ;
                    l0indxL1values[templ0]=l1 ;
                    goto l ;
                }
                templ0+=ans[f+1] ;
                buffer-= ans[f+1] ;
            }
            l0indxL1values[templ0]=0 ;
            l:;
        }

        vii l1indxl0value(3001,-1) ;
        for(int e=0 ;e<ans.size() ;e+=2){
            int templ0=0 ;
            int buffer = k ;
            for(int f=e ;f<ans.size() ;f+=2){ // we are finding l0 max from e
                templ0+=ans[f+1] ;
                if(buffer<ans[(f+2)%ans.size()]){
                    templ0+= buffer ;
                    // now calculate the l1 and put this value to l0indx[temp]
                    int l1 =0 ;
                    for(int g =0 ;g<e ;g++)l1=max(l1,ans[(g+2)%ans.size()]) ;
                    for(int g = f+2 ;g<ans.size() ;g+=2)l1=max(l1,ans[(g+2)%ans.size()]) ;
                    l1=max(l1,ans[(f+2)%ans.size()]-buffer) ;
                    l1indxl0value[templ0]=l1 ;
                    goto lk ;
                }
                templ0+=ans[(f+2)%ans.size()] ;
                buffer-= ans[(f+2)%ans.size()] ;
            }
            l1indxl0value[templ0]=0 ;
            lk:;
        }
        // now we are finding the ans
        for(int number=1 ;number<=n ;number++){ // loop of 3000
            int as =0 ;
            for(int e=0 ;e<3001 ;e++){
                if(l0indxL1values[e]!=-1)as= max(as ,number*e+l0indxL1values[e]) ;
            }
            for(int e=0 ;e<3001 ;e++){
                if(l1indxl0value[e]!=-1)as= max(as ,number*l1indxl0value[e]+e) ;
            }
            cout<<as<<" ";
        }
        cout<<endl ;
    }
}