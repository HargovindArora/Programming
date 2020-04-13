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
}

void intersection(node *head1, node *head2){

    node *temp1 = head1, *temp2;
    int flag = 0;
    while(temp1!=NULL){
        temp2 = head2;
        while(temp2!=NULL){
            if(temp1->data==temp2->data){
                flag = 1;
                break;
            }
            else{
                temp2 = temp2->next;
            }
        }
        if(flag==1){
            cout << temp2->data << endl;
            return;
        }
        else{
            temp1 = temp1->next;
        }
    }
    cout << -1 << endl;

    return;
}

int main(){

    int n1;
    cin >> n1;
    node *head1 = NULL;
    while(n1--){
        int x;
        cin >> x;
        insertAtTail(head1, x);
    }
    int n2;
    cin >> n2;
    node *head2 = NULL;
    while(n2--){
        int x;
        cin >> x;
        insertAtTail(head2, x);
    }

    intersection(head1, head2);

    return 0;
}