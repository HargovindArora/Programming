#include<iostream>
using namespace std;

int mat[1001][1001];
int dp[1001][1001];

int minCostBottomUp(int r, int c){

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){

            if(i==0 and j==0){
                dp[i][j] = mat[i][j];
            }
            else if(i==0){
                dp[i][j] = dp[0][j-1]+mat[i][j];
            }
            else if(j==0){
                dp[i][j] = dp[i-1][0]+mat[i][j];
            }
            else{
                dp[i][j] = min(dp[i-1][j], dp[i][j-1])+mat[i][j];
            }
        }
    }
    return dp[r-1][c-1];
}

int main(){

    int r, c;
    cin >> r >> c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> mat[i][j];
        }
    }
    cout << minCostBottomUp(r, c) << endl;

    return 0;
}