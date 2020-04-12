#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


class node{

public:
    int data;
    node* next;

    node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtEnd(node* &head, int data){

    if(head == NULL){
        head = new node(data);
        return;
    }
    node *tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = new node(data);
    return;
}

void moveToFront(node* &head){

    if(head==NULL || head->next==NULL){
        return;
    }
    node *temp = head, *pre=NULL;
    while(temp->next!=NULL){
        pre = temp;
        temp = temp->next;
    }
    pre->next = NULL;
    temp->next = head;
    head = temp;
    return;
}

void print(node *head){

    while(head!=NULL){
        cout << head->data << " ";
        head = head->next;
    }

}

int main(){

    int n;
    cin >> n;
    node *head = NULL;
    int x;    
    for(int i=1; i<=n; i++){
        cin >> x;
        insertAtEnd(head, x);
    }

    int k;
    cin >> k;

    for(int i=0; i<k; i++){
        moveToFront(head);
    }

    print(head);
    cout << endl;

    return 0;    
}