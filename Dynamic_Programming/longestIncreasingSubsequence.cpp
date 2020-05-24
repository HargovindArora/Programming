#include<iostream>
using namespace std;

int lisBottomUp(int arr[100], int n){

    int dp[101];
    for(int i=0; i<n; i++){
        dp[i] = 1;
    }
    int maxLen=-1;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j]<=arr[i]){
                int curLen = 1+dp[j];
                dp[i] = max(dp[i], curLen);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}

int main(){

    int arr[100];
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int ans = lisBottomUp(arr, n);
    cout << ans << endl;
    return 0;
}