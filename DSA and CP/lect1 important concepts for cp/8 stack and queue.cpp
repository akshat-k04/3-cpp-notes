 #include <bits/stdc++.h>
using namespace std ;
int main(){
    // stack is LIFO data structures i.e last in first out
    //queues is FIFO data structures i.e. first in first out
     stack<int>  s ;
     s.push(1);
     s.push(2);
     s.push(40);
     s.push(0);
     while(!s.empty()){
        cout<<s.top()<<endl ; // cout<<s.top() will print last element 
        s.pop(); //s.pop() will remove the last element 
     }
     cout<<endl ;
     queue<int> q ;

     q.push(1);
     q.push(2);
     q.push(40);
     q.push(0);

     while(!q.empty()){
        cout<<q.front()<<endl ; // cout<<s.front() will print first element 
        q.pop(); //s.pop() will remove the first element 
     }
}