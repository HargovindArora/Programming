#include<iostream>
#include<list>
using namespace std;

class Queue{
    int cs;
    list<int> q;
public:
    Queue(){
        this->cs = 0;
    }

    bool isEmpty(){
        return this->cs == 0;
    }

    void enqueue(int data){
        this->q.push_back(data);
        this->cs += 1;
    }

    void dequeue(){
        if(!isEmpty()){
            this->cs -= 1;
            this->q.pop_front();
        }
    }

    int getFront(){
        return this->q.front();
    }

};

int main(int argc, char const *argv[]){

    Queue q;
    for(int i=1; i<=9; i++){
        q.enqueue(i);
    }
    q.dequeue();
    q.enqueue(10);
    while(!q.isEmpty()){
        cout << q.getFront() << endl;
        q.dequeue();
    }

    return 0;
}