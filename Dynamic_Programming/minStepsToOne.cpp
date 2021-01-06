#include<iostream>
#include<climits>
using namespace std;

// n -> n/3, n/2, n-1

int minStepsTopDown(int n, int dp[]){

    if(n==1){
        return 0; //steps
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;
    if(n%3==0){
        op1 = minStepsTopDown(n/3, dp)+1;
    }
    if(n%2==0){
        op2 = minStepsTopDown(n/2, dp)+1;
    }
    op3 = minStepsTopDown(n-1, dp)+1;
    int ans = min(op1, min(op2, op3));
    return dp[n] = ans;
}

int minStepsBottomUp(int n){

    int dp[n+1] = {0};
    dp[1] = 0;
    for(int i=2; i<=n; i++){
        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;
        if(i%3==0){
            op1 = dp[i/3]+1;
        }
        if(i%2==0){
            op2 = dp[i/2]+1;
        }
        op3 = dp[i-1]+1;
        dp[i] = min(min(op1, op2), op3);
    }
    return dp[n];
}

int main(){

    int n;
    cin >> n;
    int dp[n+1] = {0};
    cout << minStepsBottomUp(n) << endl;

    return 0;
}