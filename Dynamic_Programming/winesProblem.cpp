#include<iostream>
using namespace std;

int winesTopDown(int wines[], int i, int j, int y, int dp[][100]){

    if(i>j){
        return 0;
    }
    if(dp[i][j]!=0){
        return dp[i][j];
    }
    int op1 = wines[i]*y + winesTopDown(wines, i+1, j, y+1, dp);
    int op2 = wines[j]*y + winesTopDown(wines, i, j-1, y+1, dp);
    return dp[i][j] = max(op1, op2);
}

int main(){

    int wines[] = {2,3,5,1,4};
    int n = sizeof(wines)/sizeof(int);
    int dp[100][100] = {0};
    int y=1;
    cout << winesTopDown(wines, 0, n-1, y, dp) << endl;
    return 0;
}