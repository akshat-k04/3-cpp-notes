#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define pob pop_back
#define fir

class node{
    public:
    int val ;
    node* next ;

    node(int a){
        val=a ;
        next = NULL ;
    }
} ;

void insert_at_last(node * &head,int n){
    if(head==NULL) head = new node(n) ;
    else insert_at_last(head->next,n) ;
}
void insert_at_head(node * & head ,int n){
    node * temp = new  node(n) ;
    temp->next = head ;
    head = temp ;
}

void print(node * head){
    while(head!=NULL){
        cout<<head->val<<" " ;
        head = head->next ;
    }
    cout<<endl ;
}

void reverse_iteratively(node * & head){
    
    node * prev ;node* curr ;node* nx ;
    if(head->next==NULL)return ;
    else{
        prev = NULL ;curr = head ;
        while(curr!=NULL){ 
            nx = curr->next ;
            curr->next = prev ;
            prev = curr ; curr=nx ;
        }
        head = prev ;
        
    }
}

node* reverse_recursively(node* head,node* prev){
    if(head==NULL)return  prev ;
    node * temp = head->next ;
    head->next = prev ;
    return reverse_recursively(temp,head) ;
}

node* reverse_k_node(node *  head , int k){
    node * prev=NULL ; node * curr=head ; node * nxt ;
    for(int e=0 ;e<k&& curr!=NULL ;e++){
        nxt = curr->next ;
        curr->next= prev ;
        prev = curr ; curr= nxt ;
    }
    if(curr==NULL)return prev ;
    head->next = reverse_k_node(curr ,k) ;
    return prev ;
}

bool cycle_detection(node * head){
    node* slow = head ; node *fast = head->next ;
    while(true){
        if(fast==NULL|| slow==NULL|| fast->next==NULL)return false ;
        else if (slow==fast)return true ;
        slow =slow->next ;
        fast = fast->next->next ;
    }
}

int main(){
    node * head = NULL ;
    int n ;
    cin>>n ;
    while(n!=-1){
        insert_at_last(head , n) ;
        cin>>n ;
    }
    cin>> n ;
    while(n!=-1){
        insert_at_head(head , n) ;
        cin>>n ;
    }
    print(head) ;
    reverse_iteratively(head) ;

    print(head) ;
    head = reverse_recursively(head,NULL) ;

    print(head) ;
    head= reverse_k_node(head,2) ;

    print(head) ;
}