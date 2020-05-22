#include<iostream>
#include<climits>
using namespace std;

int minCoinsTopDown(int n, int coins[], int T, int dp[]){

    if(n==0){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int ans = INT_MAX;
    for(int i=0; i<T; i++){
        if((n-coins[i])>=0){
            int subProb = minCoinsTopDown(n-coins[i], coins, T, dp)+1;
            ans = min(ans, subProb);
        }
    }
    dp[n] = ans;
    return dp[n];
}

int minCOinsBottomUp(int n, int coins[], int T){

    int dp[n+1] = {0};
    for(int i=1; i<=n; i++){
        dp[i] = INT_MAX;
        for(int j=0; j<T; j++){
            if((i-coins[j])>=0){
                int subProb = dp[i-coins[j]];;
                dp[i] = min(dp[i], subProb+1);
            }
        }
    }
    return dp[n];
}

int main(){

    int n;
    cin >> n;
    int coins[] = {1, 7, 10};
    int dp[n+1] = {0};
    int T = sizeof(coins)/sizeof(int);
    cout << minCOinsBottomUp(n, coins, T) << endl;

    return 0;
}