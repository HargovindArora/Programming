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

bool isPalindrome(node *&head){

    if(head == NULL){
        return true;
    }
    if(head->next==NULL){
        return true;
    }
    node *tail = head, *pre;
    while(tail->next!=NULL){
        pre = tail;
        tail = tail->next;
    }
    if(tail->data == head->data){
        pre->next = NULL;
        bool x = isPalindrome(head->next);
        if(x){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

int main(){

    int n;
    cin >> n;
    node *head = NULL;
    while(n--){
        int x;
        cin >> x;
        insertAtTail(head, x);
    }
    bool is = isPalindrome(head);
    if(is){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    return 0;
}