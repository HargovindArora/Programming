#include<iostream>
#include<cstring>
using namespace std;

int lcsBottomUp(char a[1010], char b[1010], char c[1010]){

    int m = strlen(a);
    int n = strlen(b);
    int o = strlen(c);
    int dp[m+1][n+1][o+1];

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            for(int k=0; k<=o; k++){

                if (i == 0 || j == 0 || k==0) 
                    dp[i][j][k] = 0;
                else if(a[i-1]==b[j-1] && b[j-1]==c[k-1]){
                    dp[i][j][k] = 1+dp[i-1][j-1][k-1];
                }
                else{
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
                }

            }
        }
    }

    return dp[m][n][o];
}

int main(){

    char a[1010], b[1010], c[1010];
    cin >> a >> b >> c;
    cout << lcsBottomUp(a, b, c) << endl;

    return 0;
}