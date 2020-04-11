#include<iostream>
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

// class LinkedList{

//     node* head;
//     node* tail;

// public:
//     LinkedList(){
//         head = NULL;
//         tail = NULL;
//     }
//     void insert(){

//     }

// };

// Passing the pointer variable by reference
void insertAtHead(node* &head, int data){

    node* n = new node(data);
    n->next = head;
    head = n;
}

int length(node* head){
    int len = 0;
    while(head!=NULL){
        head = head->next;
        len += 1;
    }
    return len;
}

void insertAtTail(node* &head, int data){

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

void insertInMiddle(node* &head, int p, int data){

    if(head==NULL || p==0){
        return insertAtHead(head, data);
    }
    else if(p>length(head)){
        return insertAtTail(head, data);
    }
    else{
        int jump=1;
        node* temp = head;
        while(jump<p-1){
            temp = temp->next;
            jump++;
        }
        node* n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }
}

// Head passed by value
void print(node* head){

    // node* temp = head;
    while(head!=NULL){
        cout << head->data << "->";
        head = head->next;
    }

}

void deleteAtHead(node* &head){

    if(head==NULL){
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
    return;
}

void deleteAtTail(node* &head){

    node* prev = NULL;
    node* temp = head;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    delete temp;
    prev->next = NULL;
    return;
}

void deleteInTheMiddle(node* &head, int pos){

    if(head==NULL){
        return;
    }
    node* temp = head;
    node* prev = NULL;
    int jump=1;
    while(jump<pos){
        prev = temp;
        temp = temp->next;
        jump++;
    }
    prev->next = temp->next;
    delete temp;
    return;
}

bool searchRecursive(node* head, int key){

    if(head==NULL){
        return false;
    }
    if(head->data==key){
        return true;
    }
    else{
        return searchRecursive(head->next, key);
    }
}

bool searchIterative(node* head, int key){

    while(head!=NULL){
        if(head->data==key){
            return true;
        }
        head = head->next;
    }
    return false;
}

void makeList(node* &head){

    int data;
    cin >> data;

    while(data!=-1){
        insertAtTail(head, data);
        cin >> data;
    }
}

istream& operator >> (istream &is, node* &head){
    makeList(head);
    return is;
}

ostream& operator << (ostream &os, node* head){
    print(head);
    return os;
}

void reverse(node* &head){

    node* C = head;
    node* P = NULL;
    node* N;
    while(C!=NULL){
        // Store the next node
        N = C->next;
        // Point the current node's next pointer to the previos node
        C->next = P;
        // Update the current node and the previous node
        P = C;
        C = N;
    }

    head = P;
}

node* reverseRec(node* head){

    if(head->next==NULL || head==NULL){
        return head;
    }
    node* smallHead = reverseRec(head->next);
    node*C = head;
    C->next->next = C;
    C->next = NULL;
    return smallHead;
}

node* midPoint(node* head){

    if(head==NULL || head->next==NULL){
        return head;
    }
    node* slow = head;
    node* fast = head->next;

    while(fast!=NULL && fast->next!=NULL){

        fast = fast->next->next;
        slow = slow->next;

    }
    return slow;
}

node* kThNodeFromEnd(node* head, int k){

    if(head==NULL || head->next==NULL){
        return head;
    }
    node* fast = head;
    node* slow = head;

    int jump=0;
    while(jump<k){
        fast = fast->next;
        jump++;
    }
    while(fast!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

node* merge(node* a, node* b){

    if(a==NULL){
        return b;
    }
    else if(b==NULL){
        return a;
    }

    node* c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next, b);
    }
    else {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

int main(){

    // node* head=NULL;
    // insertAtHead(head, 5);
    // insertAtHead(head, 4);
    // insertAtHead(head, 3);

    // insertAtTail(head, 10);
    // insertAtTail(head, 11);
    // insertInMiddle(head, 3, 24);
    // insertInMiddle(head, 5, 22);
    // print(head);
    // cout << endl;
    // deleteAtHead(head);
    // deleteAtTail(head);
    // deleteInTheMiddle(head, 3);

    // if(searchRecursive(head, 22)){
    //     cout << "This is element is present!" << endl;
    // }
    // else{
    //     cout << "The element is not present!" << endl;
    // }
    // if(searchIterative(head, 11)){
    //     cout << "The element is present!" << endl;
    // }
    // else{
    //     cout << "The element is not present!" << endl;
    // }

    // makeList(head);

    // node* head1=NULL;
    // node* head2=NULL;

    // cin >> head1 >> head2;
    // cout << head1 << endl << head2 << endl;

    // reverse(head);
    // cout << head << endl;

    // node* x = midPoint(head);
    // cout << x->data << endl;

    // node* y = kThNodeFromEnd(head, 3);
    // cout << y->data << endl;

    node* head1 = NULL;
    node* head2 = NULL;

    cin >> head1 >> head2;
    cout << head1 << endl << head2 << endl;

    head1 = merge(head1, head2);

    cout << head1 << endl;

    return 0;
}