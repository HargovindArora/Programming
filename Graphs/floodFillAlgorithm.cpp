#include<iostream>
#include<list>
#include<map>
using namespace std;

int r, c;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void printMat(char mat[][50]){
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << mat[i][j];
        }
        cout << endl;
    }
}

void floodFill(char mat[][50], int i, int j, char ch, char color){

    if(i<0 || j<0 || i>=r || j>=c){
        return;
    }
    if(mat[i][j]!=ch){
        return;
    }
    mat[i][j] = color;
    for(int k=0; k<4; k++){
        floodFill(mat, i+dx[k], j+dy[k], ch, color);
    }
}

int main(){

    cin >> r >> c;
    char input[15][50];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> input[i][j];
        }
    }

    printMat(input);
    floodFill(input, 8, 13, '.', 'R');
    printMat(input);

    return 0;
}