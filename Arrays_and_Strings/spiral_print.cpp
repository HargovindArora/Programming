#include<iostream>
using namespace std;

void readMatrix(int a[][10], int r, int c){
    int value = 1;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            a[i][j] = value;
            value++;
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

void spiralPrint(int a[][10], int r, int c){

    int startRow=0, startCol=0, endRow=r-1, endCol=c-1;

    while(startRow<=endRow && startCol<=endCol){

        for(int j=startCol; j<=endCol; j++){
            cout << a[startRow][j] << ", ";
        }
        startRow++;

        for(int i=startRow; i<=endRow; i++){
            cout << a[i][endCol] << ", ";
        }
        endCol--;

        if(startRow<endRow){
            for(int j=endCol; j>=startCol; j--){
                cout << a[endRow][j] << ", ";
            }
            endRow--;
        }   
        if(startCol<endCol){
            for(int i=endRow; i>=startRow; i--){
                cout << a[i][startCol] << ", ";
            }
            startCol++;
        }

    }


}

int main(){

    int r,c;
    cin >> r >>c;
    int a[10][10];

    readMatrix(a, r, c);
    printMatrix(a, r, c);
    spiralPrint(a, r, c);

    return 0;
}