#include<iostream>
#include<vector>
#define endl '\n'
using namespace std;

template<typename T, typename U>
class Stack{

private:
    vector<T> v;
    // vector<U> x;
public:
    void push(T data){
        v.push_back(data);
    }
    bool empty(){
        return v.size()==0;
    }
    void pop(){
        if(!empty()){
            v.pop_back();
        }
    }
    T top(){
        return v[v.size()-1];
    }
};

int main(){

    Stack<int, char> s;

    for(int i=1; i<=18; i++){
        s.push(i*i);
    }
    while(!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }

    return 0;
}