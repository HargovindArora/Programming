#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Queue{
    private:
        stack<int> a, b;
    public:
        void enqueue(int data){

            while(!a.empty()){
                int x = a.top();
                a.pop();
                b.push(x);
            }
            a.push(data);
            while(!b.empty()){
                a.push(b.top());
                b.pop();
            }
        }

        int dequeue(){

            if(a.empty()){
                exit(0);
            }
            int x = a.top();
            a.pop();
            return x;

        }
};

int main(){

    int n;
    cin >> n;
    Queue q;
    for(int i=0; i<n; i++){
        q.enqueue(i);
    }
    for(int i=0; i<n; i++){
        cout << q.dequeue() << " ";
    }

    return 0;
}