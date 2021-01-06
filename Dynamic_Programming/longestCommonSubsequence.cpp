#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int lcsTopDown(string s1, string s2, int i, int j, vector<vector<int>> &dp){

    if(i==s1.length() or j==s2.length()) return 0;

    if(dp[i][j]!=-1){
        return dp[i][j] = 0;
    }

    if(s1[i]==s2[j]) return dp[i][j] = 1+lcsTopDown(s1, s2, i+1, j+1, dp);

    int op1 = lcsTopDown(s1, s2, i+1, j, dp);
    int op2 = lcsTopDown(s1, s2, i, j+1, dp);

    return dp[i][j] = max(op1, op2);
}

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

    string str1, str2;
    cin >> str1 >> str2;

    int n1 = str1.length();
    int n2 = str2.length();

    vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));

    int ans = lcsTopDown(str1, str2, 0, 0, dp);
    cout << ans << endl;

    return 0;
}