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
    node *temp = head;
    while(temp->next!=NULL){
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
}

void evenAfterOdd(node *&head){

    node *evenStart = NULL;
    node *evenEnd = NULL;
    node *oddStart = NULL;
    node *oddEnd = NULL;
    node *current = head;

    while(current!=NULL){

        int val = current->data;
        if(val%2!=0){
            if(oddStart==NULL){
                oddStart = current;
                oddEnd = oddStart;
            }
            else{
                oddEnd->next = current;
                oddEnd = oddEnd->next;
            }
        }
        else{
            if(evenStart==NULL){
                evenStart = current;
                evenEnd = evenStart;
            }
            else{
                evenEnd->next = current;
                evenEnd = evenEnd->next;
            }
        }

        current = current->next;
    }

    if(oddStart==NULL || evenStart==NULL){
        return;
    }
    oddEnd->next = evenStart;
    evenEnd->next = NULL;
    head = oddStart;

    return;
}

int main(){

    int n;
    cin >> n;
    node *head = NULL;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        insertAtTail(head, x);
    }
    evenAfterOdd(head);
    print(head);
    cout << endl;

    return 0;
}