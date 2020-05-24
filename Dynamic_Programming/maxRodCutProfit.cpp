#include<iostream>
using namespace std;

int maxProfitTopDown(int arr[], int totalLen, int dp[]){

    if(totalLen==0){
        return 0;
    }
    if(dp[totalLen]!=0){
        return dp[totalLen];
    }
    int best = 0;
    for(int len=1; len<=totalLen; len++){
        int netProfit = arr[len] + maxProfitTopDown(arr, totalLen-len, dp);
        best = max(best, netProfit);
    }
    return dp[totalLen]=best;
}

int maxProfitBottomUp(int arr[], int totalLen){
    
    int dp[1000] = {0};
    for(int len=1; len<=totalLen; len++){
        int best = 0;
        for(int cut=1; cut<=len; cut++){
            best = max(best, arr[cut] + dp[len-cut]);
        }
        dp[len] = best;
    }
    return dp[totalLen];
}

int main(){

    int price[1000];
    int totalLen;
    cin >> totalLen;
    for(int eachPiece=1; eachPiece<=totalLen; eachPiece++){
        cin >> price[eachPiece];
    }
    int dp[1000] = {0};
    int ans = maxProfitBottomUp(price, totalLen);
    cout << ans << endl;

    return 0;
}