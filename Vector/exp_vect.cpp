#include<iostream>
#include "vector.h"
using namespace std;


int main(){

    vector<char> x;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    for(int i=0; i<x.getSize(); i++){
        cout << x[i] << ", ";
    }
    cout << endl;

    return 0;
}