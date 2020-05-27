#include<iostream>
#include<cstring>
using namespace std;

void lcsBottomUp(char X[1010], char Y[1010]){

    int m = strlen(X);
    int n = strlen(Y);
    int dp[1010][1010] = {0};
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            int q=0;
            if(X[i-1]==Y[j-1]){
                q = 1+dp[i-1][j-1];
            }
            else{
                q = max(dp[i-1][j], dp[i][j-1]);
            }
            dp[i][j] = q;
        }
    }
    int index = dp[m][n];
    int i=m, j=n;
    char lcs[index+1];
    lcs[index] = '\0';
    while(i>0 && j>0){

        if(X[i-1]==Y[j-1]){
            lcs[index-1] = X[i-1];
            i--, j--, index--;
        }
        else if(dp[i-1][j]>=dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout << lcs << endl;
}

int main(){

    char str1[1010], str2[1010];
    cin >> str1 >> str2;
    lcsBottomUp(str1, str2);

    return 0;
}