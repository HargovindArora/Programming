#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

class node{

public:
    int data;
    node *next;

    node(int data){
        this->data = data;
        next = NULL;
    }
};

void insertAtTail(node *&head, int data){

    if(head==NULL){
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

void print(node *head){

    while(head!=NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

node *reversePartly(node *head, int k){

    node *current = head;
    node *next = NULL;
    node *prev = NULL;
    int count = 0;

    while(current!=NULL && count<k){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if(next!=NULL){
        head->next = reversePartly(next, k);
    }

    return prev;
}

int main(){

    int n, k;
    cin >> n >> k;
    node *head = NULL;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        insertAtTail(head, x);
    }
    
    node *head_new = reversePartly(head, k);
    print(head_new);

    return 0;
}