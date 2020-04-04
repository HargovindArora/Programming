#include<iostream>
using namespace std;
int count=0;

bool ratInMaze(char maze[10][10], int soln[][10], int i, int j, int m, int n){

    if(i==m && j==n){
        soln[m][n] = 1;

        if(count==0){
            for(int k=0; k<=m; k++){
                for(int l=0; l<=n; l++){
                    cout << soln[k][l] << " ";
                }
            cout << endl;
            }
        }
        count++;
        cout << endl;
        return true;
    }

    if(i>m || j>n){
        return false;
    }

    if(maze[i][j]=='X'){
        return false;
    }

    soln[i][j] = 1;

    bool rightPath = ratInMaze(maze, soln, i, j+1, m, n);
    bool downPath = ratInMaze(maze, soln, i+1, j, m, n);

    soln[i][j] = 0;

    if((rightPath || downPath)){
        return true;
    }
    
    return false;
}


int main(){

    char maze[10][10] = {
                        "0000",
                        "00X0",
                        "000X",
                        "0000"
    };

    int soln[10][10] = {0};

    bool ans = ratInMaze(maze, soln, 0, 0, 3, 3);

    if(!ans){
        cout << "Paths doesn't exists!" << endl;
    }
    cout << "Number of paths are " << count << endl;
    return 0;
}