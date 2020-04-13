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
    return;
}

void detectAndRemoveLoop(node *&head) 
{ 
    if (head == NULL || head->next == NULL) 
        return; 
  
    node *slow = head, *fast = head; 
    slow = slow->next; 
    fast = fast->next->next; 

    while (fast!=NULL && fast->next!=NULL) { 
        if (slow == fast) 
            break; 
        slow = slow->next; 
        fast = fast->next->next; 
    } 
  
    /* If loop exists */
    if (slow == fast) { 
        slow = head; 
        while (slow->next != fast->next) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
  
        /* since fast->next is the looping point */
        fast->next = NULL; /* remove loop */
    } 
} 

int main(){

    int x;
    cin >> x;
    node *head = NULL;
    while(x!=-1){
        insertAtTail(head, x);
        cin >> x;
    }
	head->next->next->next->next->next = head->next;
    detectAndRemoveLoop(head);
    print(head);
    cout << endl;

    return 0;
}

