#include<iostream>
#include<cstring>
using namespace std;

int main(){

    char str[] = "Hey there, I am learning, C++";   
    char *ptr;

    ptr = strtok(str, " ,");
    
    while(ptr!=NULL){

        cout << ptr << endl;
        ptr = strtok(NULL, " ,");
    }

    return 0;
}