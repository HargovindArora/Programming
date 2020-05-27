#include<iostream>
#include<algorithm>
using namespace std;
int max(int a, int b) { return (a > b) ? a : b; } 
  
int knapSack(int W, int wt[], int val[], int n) 
{ 
    if (n == 0 || W == 0) 
        return 0; 
    if (wt[n - 1] > W) 
        return knapSack(W, wt, val, n - 1); 
    else
        return max( 
            val[n - 1] + knapSack(W - wt[n - 1],  
                                    wt, val, n - 1), 
            knapSack(W, wt, val, n - 1)); 
}

int knapSackBottomUp(int W, int wt[], int val[], int n){

    int i,w;
    int dp[n+1][W+1];
    for(i=0; i<=n; i++){
        for(w=0; w<=W; w++){
            if (i == 0 || w == 0) 
                dp[i][w] = 0; 
            else if(wt[i-1]<=w){
                dp[i][w] = max(val[i-1]+dp[i-1][w-wt[i-1]], dp[i-1][w]);
            }
            else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

int main(){

    int n, s;
    cin >> n >> s;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int b[n];
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    cout << knapSackBottomUp(s, a, b, n) << endl;

    return 0;
}