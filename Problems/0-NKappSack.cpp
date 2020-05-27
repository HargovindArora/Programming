#include<iostream>
using namespace std;

int zeroNKSBottomUp(int w, int wt[], int val[], int n){

    int dp[w+1] = {0};
    for(int i=0; i<=w; i++){
        for(int j=0; j<n; j++){

            if(wt[j]<=i){
                dp[i] = max(dp[i], dp[i-wt[j]]+val[j]);
            }
        }
    }
    return dp[w];
}   

int main(){

    int n, w;
    cin >> n >> w;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int b[n];
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    cout << zeroNKSBottomUp(w, a, b, n) << endl;

    return 0;
}