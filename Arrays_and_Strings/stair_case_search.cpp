#include<iostream>
using namespace std;

void readMatrix(int a[][10], int r, int c){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> a[i][j];
        }
    }
}

void stairCaseSearch(int a[][10], int r, int c, int key){

    int j=c-1, i=0;

    while(i<r&&j>=0){
        if(a[i][j]==key){
            cout << "Found at position " << i << "," << j<<endl;
            return;
        }
        else if(a[i][j]>key){
            j--;
        }
        else{
            i++;
        }
    }

    cout << "Element not found\n";
    return;
}

int main(){

    int r,c;
    cin >> r >>c;
    int a[10][10];

    readMatrix(a, r, c);
    int key;
    cin >> key;
    stairCaseSearch(a, r, c, key);

    return 0;
}