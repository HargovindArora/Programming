#include<algorithm>
#include<iostream>
#include<climits>
using namespace std;

//  Time Complexity O(NLOG(N))
int lisBottomUp(int arr[100], int n){

    int dp[n+1];
    dp[0] = INT_MIN;
    for(int i=1; i<=n; i++){
        dp[i] = INT_MAX;
    }
    for(int i=0; i<n; i++){
        int length = upper_bound(dp, dp+n+1, arr[i]) - dp;
        if(dp[length-1]<arr[i] and arr[i]<dp[length]){
            dp[length] = arr[i];
        }
        
    }
    int lis = 0;
    for(int i=1; i<=n; i++){
        if(dp[i]!=INT_MAX){
            lis = i;
        }
    }
    return lis;
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