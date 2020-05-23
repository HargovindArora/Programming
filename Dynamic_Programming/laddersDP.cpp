#include<iostream>
using namespace std;

int laddersTopDown(int n, int k, int dp[]){

    if(n==0){
        return 1;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int ways = 0;
    for(int i=1; i<=k; i++){
        if(n-i>=0){
            ways += laddersTopDown(n-i, k, dp);
        }
    }
    return dp[n] = ways;
}

int main(){

    int n, k;
    cin >> n >> k;
    int dp[n+1] = {0};
    cout << laddersTopDown(n, k, dp) << endl;

    return 0;
}