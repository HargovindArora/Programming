#include<iostream>
#define endl '\n'
using namespace std;

class Node {

public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
    }

};

void push(Node* &head, int data){

    Node* ptr = new Node(data);
    Node* temp = head;
    ptr->next = head;
    if(head!= NULL){
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = ptr;
    }
    else{
        ptr->next = ptr;
    }
    head = ptr;
}

void printList(Node* head){

    Node* temp = head;
    while(temp->next!=head){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << " END";
}

Node* getNode(Node* &head, int data){

    Node* temp = head;
    while(temp->next!=head){
        if(temp->data==data){
            return temp;
        }
        temp = temp->next;
    }
    if(temp->data==data){
        return temp;
    }
    return NULL;
}

void deleteNode(Node* &head, int data){

    Node *del = getNode(head, data);
    if(del == NULL){
        cout << "Node not present in the linked list!" << '\n';
        return;
    }
    if(head == del){
        if(head->next==head){
            delete del;
            return;
        }
        head = del->next;
        delete del;
        return;
    }
    Node* temp = head;
    while(temp->next!=del){
        temp = temp->next;
    }
    temp->next = del->next;
    delete del;
}

int main(){

    Node *head = NULL;
    push(head, 40);
    push(head, 30);
    push(head, 20);
    push(head, 10);
    push(head, 0);
    printList(head);
    cout << endl;
    deleteNode(head, 30);
    printList(head);
    cout << endl;
    return 0;
}