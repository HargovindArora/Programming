#include<iostream>
using namespace std;

template<typename T>
class vector{

    T *arr;
    int cs;
    int maxSize;

public:

    vector(int defaultSize = 4){
        maxSize = defaultSize;
        cs = 0;
        arr = new T[maxSize];
    }
    void push_back(const T data){
        if(cs==maxSize){
            T *oldArr = arr;
            arr = new T[2*maxSize];
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
    T at(int i){
        return arr[i];
    }
    T & operator [] (int i){
        return arr[i];
    }

};
template<typename T>
ostream& operator << (ostream &os, vector<T> &v){
    v.print();
    return os;
}
template<typename T>
istream& operator >> (istream &is, vector<T> &v){
    
    return is;
}