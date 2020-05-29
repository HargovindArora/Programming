#include<iostream>
#include<cstring>
using namespace std;

int main(){

    char a[10][100];

    int n;
    cin >> n;
    cin.ignore();

    for(int i=0; i<n; i++){
        cin.getline(a[i],100);
    }

    char key[100];
    cin.getline(key, 100);

    int i=0;
    for(i=0; i<n; i++){
        if(strcmp(key, a[i])==0){
            cout << "String found at index " << i << endl;
            break; 
        }
    }

    if(i==n){
        cout << "String not found!" << endl;
    }

    return 0;
}