#include<iostream>
#include<cstring>
using namespace std;

int lcsBottomUp(char X[1010], char Y[1010]){

    int m = strlen(X);
    int n = strlen(Y);
    int dp[100][100] = {0};
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
    return dp[m][n];
}

int main(){

    char str1[1010], str2[1010];
    cin >> str1 >> str2;
    int ans = lcsBottomUp(str1, str2);
    cout << ans << endl;

    return 0;
}