#include<iostream>
using namespace std;

void wavePrint(int a[][10], int r, int c){

    for(int j=0; j<c; j++){
        if(j&1){
            for(int i=r-1; i>=0; i--){
                cout << a[i][j] << ", ";
            }
        }
        else{
            for(int i=0; i<r; i++){
                cout << a[i][j] << ", ";
            }
        }
    }

}

void getMatrix(int a[][10], int r, int c){

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> a[i][j];
        }
    }

}

void printMatrix(int a[][10], int r, int c){

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << a[i][j] << ", ";
        }
        cout << endl;
    }

}

int main(){

    int r, c;
    cin >> r >> c;
    int a[10][10];

    getMatrix(a, r, c);
    printMatrix(a, r, c);
    wavePrint(a, r, c);

    return 0;
}