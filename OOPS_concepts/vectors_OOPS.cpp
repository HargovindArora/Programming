#include<iostream>
using namespace std;


class Vector{

    int *arr;
    int cs;
    int maxSize;

public:

    Vector(int defaultSize = 4){
        maxSize = defaultSize;
        cs = 0;
        arr = new int[maxSize];
    }
    void push_back(int data){
        if(cs==maxSize){
            int *oldArr = arr;
            arr = new int[2*maxSize];
            maxSize *= 2;
            for(int i=0; i<cs; i++){
                arr[i] = oldArr[i];
            }
            delete [] oldArr;
        }
        arr[cs] = data;
        cs++;
    }
    void operator () (string s){
        cout << s << endl;
    }
    bool empty(){
        return cs==0;
    }
    int getSize() const{
        return cs;
    }
    int getMaxSize() const{
        return maxSize;
    }
    void pop_back(){
        if(!empty()){
            cs--;
        }
    }
    void print() const{
        for(int i=0; i<cs; i++){
            cout << arr[i] << ", ";
        }
        cout << endl;
    }
    int at(int i){
        return arr[i];
    }
    int & operator [] (int i){
        return arr[i];
    }

};

ostream& operator << (ostream &os, Vector &v){
    v.print();
    return os;
}

istream& operator >> (istream &is, Vector &v){
    
    return is;
}

int main(){

    Vector v;
    // [FUNCTOR] OR FUNCTIONAL OBJECTS! FOR ROUND BRACKETS ONLY
    v("I AM LEGEND!");
    for(int i=0; i<4; i++){
        v.push_back(i*i);
    }
    v.print();
    
    cout << v.getMaxSize() << endl;
    v.push_back(16);
    cout << v.getMaxSize() << endl;
    cout << v[3] << endl;

    Vector fun(v);
    cout << v << fun;
    v[2] = 5;
    cout << v[2];
    
    return 0;
}