#include<iostream>
using namespace std;

int kOrderedLCS(int *a, int *b, int n, int m, int k){

    int dp[n+1][m+1][k+1] = {0};
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int q=0;
            if(i == 0 || j == 0) 
                dp[i][j][0] = 0;
            if(a[i-1]==b[j-1]){
                q = 1+dp[i-1][j-1][0];
            }
            else{
                q = max(dp[i-1][j][0], dp[i][j-1][0]);
            }
            dp[i][j][0] = q;
        }
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
                
            for(int x=1; x<=k; x++){
                if(i == 0 || j == 0) 
                    dp[i][j][x] = 0;
                else if(a[i-1]==b[j-1]){
                    dp[i][j][x] = max(1+dp[i-1][j-1][x], dp[i][j][x]);
                }
                else if(a[i-1]!=b[j-1]){
                    dp[i][j][x] = max(dp[i-1][j-1][x-1]+1, dp[i][j][x]);
                } 
            }

        }
    }
    return dp[n][m][k];
}

int main(){

    int n, m, k;
    cin >> n >> m >> k;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int b[n];
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    cout << kOrderedLCS(a, b, n, m, k) << endl;

    return 0;
}

// #include <iostream>
// using namespace std;

// int dp[2005][2005][8];

// int korderedLCS(int *a, int *b, int n, int m, int i, int j, int k) {
//     if(n == i or m == j) {
//         return 0;
//     }
//     if(dp[i][j][k] != -1) {
//         return dp[i][j][k];
//     }
//     int res = 0;
//     if(a[i] == b[j]){
//         res = 1 + korderedLCS(a, b, n, m, i+1, j+1, k);
//     } 
//     else{
//         if(k>0) {
//             res = 1 + korderedLCS(a, b, n, m, i+1, j+1, k-1);
//         }
//         res = max(res, korderedLCS(a, b, n, m, i+1, j, k));
//         res = max(res, korderedLCS(a, b, n, m, i, j+1, k));
//     }
//     dp[i][j][k] = res;
//     return res;
// }

// int main(int argc, char const *argv[])
// {

//     int n, m, k;
//     cin>>n>>m>>k;
//     int a[n];
//     int b[m];
//     for(int i=0;i<n;i++) {
//         cin>>a[i];
//     }
//     for(int i=0;i<m;i++) {
//         cin>>b[i];
//     }
//     for(int i=0;i<2005;i++) {
//         for(int j=0;j<2005;j++) {
//             for(int m=0;m<8;m++) {
//                 dp[i][j][m] = -1;
//             }
//         }
//     }
//     cout<< korderedLCS(a, b, n, m, 0, 0, k);
//     return 0;
// }