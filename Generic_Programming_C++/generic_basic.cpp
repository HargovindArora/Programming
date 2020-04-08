#include<iostream>
#include<list>
using namespace std;

template<typename T>

int search(T arr[], int n, T key){

    for(int i=0; i<n; i++){
        if(arr[i] == key){
            return i;
        }
    }

    return n;
}

template<class ForwardIterator, class T>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key){
    while(start!=end){
        if(*start==key){
            return start;
        }
        start++;
    }
    return end;
}

int main(){

    int arr[] = {1,2,3,4,54,67,342};
    int n = sizeof(arr)/sizeof(int);
    int key = 4;
    // cout <<search(arr, n, key) << endl; 

    float x[] = {1.1, 1.2, 1.3, 1.4};
    int y = sizeof(x)/sizeof(float);
    float ki = 1.4;
    // cout << search(x, y, ki) << endl;

    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    auto it = search(l.begin(), l.end(), 5);
    if(it == l.end()){
        cout << "Element not found" << endl;
    }
    else{
        cout << *it << endl;
    }

    return 0;
}