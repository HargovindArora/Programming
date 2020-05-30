#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int minJumpsDP(int *a, int n){

    int dp[n+1] = {0};
    int i, j;
    if(n==0 || a[0]==0){
        return INT_MAX;
    }
    for(int i=1; i<n; i++){
        dp[i] = INT_MAX;
        for(int j=0; j<i; j++){

            if(i <= j+a[j] && dp[j]!=INT_MAX){
                dp[i] = min(dp[i], dp[j]+1);
                break;
            }
        }
    }
    return dp[n-1];
}

void solve(){

    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << minJumpsDP(a, n) << endl;
    return;
}

int main(){

    int t;
    cin >> t;
    while(t--){

        solve();

    }

    return 0;
}