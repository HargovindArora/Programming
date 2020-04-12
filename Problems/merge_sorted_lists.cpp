#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

class node{

public:
    int data;
    node *next;

    node(int d){
        data = d;
        next = NULL;
    }

};

void insertAtEnd(node *&head, int data){

    if(head==NULL){
        head = new node(data);
        return;
    }
    node *temp = head;
    while (temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new node(data);
    return;
}

void print(node *head){

    while(head!=NULL){
        cout << head->data << " ";
        head = head->next;
    }
    return;
}

node *merge(node *a, node *b){

    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }

    node *c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next, b);
    }
    else{
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        node *head1 = NULL;
        for(int i=1; i<=n; i++){
            int x; 
            cin >> x;
            insertAtEnd(head1, x);
        }
        int m;
        cin >> m;
        node *head2 = NULL;
        for(int i=1; i<=m; i++){
            int x;
            cin >> x;
            insertAtEnd(head2, x);
        }
        node *head = merge(head1, head2);
        print(head);
        cout << endl;
        
    }

    return 0;
}