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

node *kthNode(node *head, int k){

    int count = 0;
    node *slow = head;
    node *fast = head;
    while(count<k){
        fast = fast->next;
        count++;
    }
    while(fast!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main(){

    node *head = NULL;
    int data;
    cin >> data;
    while(data!=-1){
        insertAtTail(head, data);
        cin >> data;
    }
    int k;
    cin >> k;

    node *kth = kthNode(head, k);

    cout << kth->data << endl;

    return 0;
}