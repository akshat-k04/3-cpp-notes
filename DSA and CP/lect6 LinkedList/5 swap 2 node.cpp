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
void swap(node * &prev , node *&swap1,node*&node2){
   if(prev!=NULL) prev->nxt = node2 ;
   node *temp = swap2->nxt ;
   swap2->nxt = swap1 ;
   swap1->nxt = temp ;
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
    deletation(head,1) ;
    print(head) ;
}