#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int ms;
    int cs;
    int front;
    int rear;
public:
    Queue(int default_size=9){
        this->front = 0;
        this->rear = default_size-1;
        this->cs = 0;
        this->ms = default_size;
        this->arr = new int[this->ms]();
    }

    bool isFull(){
        return this->cs == this->ms;
    }

    bool isEmpty(){
        return this->cs == 0;
    }

    void enqueue(int data){
        if(!isFull()){
            this->rear = (this->rear + 1)%this->ms;
            this->arr[this->rear] = data;
            this->cs += 1;
        }
    }

    void dequeue(){
        if(!isEmpty()){
            this->front = (this->front+1)%this->ms;
            this->cs-=1;
        }
    }

    int getFront(){
        return this->arr[this->front];
    }

    int & operator [] (int i){
        return arr[i];
    }

};

int main(){

    Queue q(10);
    for(int i=1; i<=6; i++){
        q.enqueue(i);
    }
    q.dequeue();
    q.enqueue(7);
    while(!q.isEmpty()){
        cout << q.getFront() << endl;
        q.dequeue();
    }

    return 0;
}