// leet code problem link :- https://leetcode.com/problems/sudoku-solver/

//approch:- dont consider it as 2 d matrix while wrting the algo. use for loop to find the 1st empty space and then try all 9 numbers put the valid number by checking in validator function if all numbers are not valid it means that we put a wrong number in previous empty spaces so go back by terminating the present function as in line 94

/* test cases:-
5 3 0 0 7 0 0 0 0 
6 0 0 1 9 5 0 0 0 
0 9 8 0 0 0 0 6 0 
8 0 0 0 6 0 0 0 3 
4 0 0 8 0 3 0 0 1 
7 0 0 0 2 0 0 0 6 
0 6 0 0 0 0 2 8 0 
0 0 0 4 1 9 0 0 5 
0 0 0 0 8 0 0 7 9

0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
*/

#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define pob pop_back
//#define fir first 
//#define sec second
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vii;

const ll largestLL= 1e18;
const int largestI = 1e9;
const ll primeInt2 = 1000000007;
const int primeInt = 998244353;

/*inbuilt functions:-
gcd :- __gcd(a,b)
*/


//solution here 


bool validate(vector<vector<char>> &a, int num,int row ,int col){
    string lt =to_string(num) ;
    char l = lt[0] ;
    for(int e=0; e<9 ; e++){
        for(int f=0 ;f<9 ; f++){
            if(a[row][f]==l){
                // cout<<1<<endl; 
                return false  ;
            }
            if(a[e][col]==l){
                // cout<<2<<endl ;
                return false  ;
            }
        }
    }
    int coli = (int)(col/3) ;
    int rowi = (int )(row/3) ;
    for(int e=3*(int)(row/3); e<3*(int)(row/3)+3 ; e++){
        for(int f=3*(int)(col/3) ;f<3*(int)(col/3)+3 ; f++){
            if(a[e][f]==l){
                
                return false  ;
            }
        }
    }
    return true ;
}


void generate(vector<vector<char>> &a , vector<vector<vector<char>>> &ans,int counted ,int counter){
    if(counter==counted){
        ans.pb(a) ;
        return ;
    }

        for(int e=0 ;e<9 ; e++){
            for(int f=0 ;f<9 ; f++){
                if(a[e][f]=='0'){
                    for(int g=1 ;g<=9; g++){
                        
                        if(validate(a,g,e,f)){
                            // cout<<"hello"<<endl ;
                            a[e][f]= to_string(g)[0] ;
                            if(ans.size()==0){ // if we want all possible solution then remove this if condition 
                                generate(a,ans,counted ,counter+1) ;

                                //1 :- if i write this then a will get solved i dont even need of ans vector but i need something bool that can be used instead of ans.size() 
                                if(ans.size()==0){
                                    a[e][f]='0' ;
                                }
                                else{
                                    return ;
                                }
                                //2 :- i use this to make code easily understandable
                                // a[e][f]=='0' ;
                            }
                        }
                    }
                    return ; // this i do this because if there is an empty space and not a single number can be put on that plce then i terminate the function , by doing this the previous number will change and again the number will fill in 
                }
            }
        }
}


int main(){
    vector<vector<char>> a ;
    vector<vector<vector<char>>> ans ;
    int counted =0 ;
    for(int e=0 ;e<9 ; e++){
        vector<char> temp ;
        for(int f=0; f<9 ; f++){
            char h ;
            cin>>h ;
            if(h=='0'){
                counted++ ;
            }
            temp.pb(h);
        }
        a.pb(temp) ;
    }
    //input is done 
    generate(a,ans,counted,0)  ;

    // for(int e=0 ;e<9 ; e++){
    //     for(int f=0 ; f<9 ; f++){
    //         cout<<a[e][f]<<" " ;
    //     }
    //     cout<<endl ;
    // }
    // cout<<endl ;

    for(int e=0 ;e<ans.size() ; e++){
        for(int f=0 ;f<9 ; f++){
            for(int g=0 ;g<9 ; g++){
                cout<<ans[e][f][g]<<" " ;
            }
            cout<<endl ;
        }
        cout<<endl ;
    }
}
















//not my approch

// bool validate(vector<vector<char>> &a, int num,int row ,int col){
//     string lt =to_string(num) ;
//     char l = lt[0] ;
//     for(int e=0; e<9 ; e++){
//         for(int f=0 ;f<9 ; f++){
//             if(a[row][f]==l){
//                 // cout<<1<<endl; 
//                 return false  ;
//             }
//             if(a[e][col]==l){
//                 // cout<<2<<endl ;
//                 return false  ;
//             }
//         }
//     }
//     int coli = (int)(col/3) ;
//     int rowi = (int )(row/3) ;
//     for(int e=3*(int)(row/3); e<3*(int)(row/3)+3 ; e++){
//         for(int f=3*(int)(col/3) ;f<3*(int)(col/3)+3 ; f++){
//             if(a[e][f]==l){
                
//                 return false  ;
//             }
//         }
//     }
//     return true ;
// }

// bool generate(vector<vector<char>> &a , vector<vector<vector<char>>> &ans,int counted ,int counter){
//     cout<<counted<<" " <<counter<<endl ;
    
//     for(int e=0 ;e<9 ; e++){
//         for(int f=0 ;f<9 ; f++){
//             if(a[e][f]=='0'){
                
//                 for(int g=1 ;g<=9; g++){
                    
//                     if(validate(a,g,e,f)){
//                         // cout<<"hello"<<endl ;
//                         a[e][f]= to_string(g)[0] ;
//                         bool next = generate(a,ans,counted ,counter+1) ;
//                         if(next){
//                             return true ;
//                         }
//                         else{
//                             a[e][f]='0' ;
//                         }
                    
//                     }
//                 }
//                 return false;
//             }
//         }
//     }
//     return true;
// }


// int main(){
//     vector<vector<char>> a ;
//     vector<vector<vector<char>>> ans ;
//     int counted =0 ;
//     for(int e=0 ;e<9 ; e++){
//         vector<char> temp ;
//         for(int f=0; f<9 ; f++){
//             char h ;
//             cin>>h ;
//             if(h=='0'){
//                 counted++ ;
//             }
//             temp.pb(h);
//         }
//         a.pb(temp) ;
//     }
//     //input is done 
//     generate(a,ans,counted,0)  ;
//     for(int f=0 ;f<9 ; f++){
//             for(int g=0 ;g<9 ; g++){
//                 cout<<a[f][g]<<" " ;
//             }
//             cout<<endl ;
//     }
// }













































