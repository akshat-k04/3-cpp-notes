// int* a ;  means a will store the address of int 

// (*a).name is same as a->name  both are same


#include <bits/stdc++.h>
using namespace std ;

class node{
    public:
        int num ;
        node* nxt ;
        node(int a){
            num = a ;
            nxt = NULL ;
        };
};

void insert(node * head,int a){
    while(head->nxt!=NULL){
        head =head->nxt ;
    }
    head->nxt = new node(a) ;
}
void print(node *head){
    cout<<head->num <<" ";
    if(head->nxt!=NULL)print(head->nxt) ;
}
void deletation(node * &head , int a){
    if(head->num==a){
        node *tp = head ;
        head=head->nxt ;
        delete tp ;
    }
    else{
        node *temp = head ;
        while(temp->nxt!=NULL &&temp->nxt->num!=a){
            temp =temp->nxt ;
        }
        if(temp->nxt!=NULL &&temp->nxt->num==a){
            node *tp = temp->nxt ;
            temp->nxt = temp->nxt->nxt ;
            delete tp ;
        }
    }
}

//iterative method
void reverse(node *&head){
    node * prev = NULL ;
    while(head->nxt!=NULL){
        node * temp = head->nxt ;
        head->nxt = prev ;
        prev = head ;
        head= temp ;
    }
    head->nxt = prev ;
}

//recursive method
void reverse(node *&head ,node *prev){
    if(head==NULL){
        head=prev ;
        return ;
    }
    node *temp = head->nxt ;
    head->nxt = prev ;
    swap(head,temp) ;
    reverse(head,temp) ;
}

int main(){
    // the linked list starts from the head 
    // so lets create the head 
    int a ;
    cin>>a ;
    node* head= new node(a) ;
    // now lets insert the number in and make linked list 
    for(int e=0 ;e<5 ;e++){
        cin>>a ;
        insert(head,a) ;
    }
    print(head) ;cout<<endl ;
    reverse(head,NULL) ;
    print(head) ;cout<<endl ;
    
}